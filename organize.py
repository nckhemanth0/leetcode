#!/usr/bin/env python3
"""
Reorganize ./solutions by topic category.

Before:
  solutions/
    1-two-sum/two-sum.py
    104-maximum-depth-of-binary-tree/...

After:
  solutions/
    Arrays/
      0001-two-sum/two-sum.py
    Trees/
      0104-maximum-depth-of-binary-tree/...

Usage:
  python3 organize.py              # dry run (shows what would move)
  python3 organize.py --apply      # actually move files
"""

import os
import re
import sys
import time
import json
import shutil
import urllib.request
import urllib.error
from pathlib import Path

SOLUTIONS_DIR = Path(__file__).parent / "solutions"
APPLY = "--apply" in sys.argv

GRAPHQL_URL = "https://leetcode.com/graphql"
QUERY = """
query getTopics($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    difficulty
    topicTags { name }
  }
}
"""

# Canonical ordering — first tag in this list wins for folder placement.
# Problems with no tag go into Uncategorized.
TOPIC_ORDER = [
    "Array", "String", "Hash Table", "Dynamic Programming", "Math",
    "Sorting", "Greedy", "Depth-First Search", "Breadth-First Search",
    "Binary Search", "Tree", "Matrix", "Bit Manipulation", "Two Pointers",
    "Stack", "Heap (Priority Queue)", "Prefix Sum", "Simulation", "Graph",
    "Counting", "Design", "Sliding Window", "Backtracking", "Recursion",
    "Linked List", "Trie", "Queue", "Divide and Conquer",
    "Number Theory", "Geometry", "Randomized", "Memoization",
]

TOPIC_ALIASES = {
    "Array": "Arrays",
    "String": "Strings",
    "Hash Table": "Hash-Tables",
    "Dynamic Programming": "Dynamic-Programming",
    "Math": "Math",
    "Sorting": "Sorting",
    "Greedy": "Greedy",
    "Depth-First Search": "DFS",
    "Breadth-First Search": "BFS",
    "Binary Search": "Binary-Search",
    "Tree": "Trees",
    "Matrix": "Matrix",
    "Bit Manipulation": "Bit-Manipulation",
    "Two Pointers": "Two-Pointers",
    "Stack": "Stack",
    "Heap (Priority Queue)": "Heap",
    "Prefix Sum": "Prefix-Sum",
    "Simulation": "Simulation",
    "Graph": "Graphs",
    "Counting": "Counting",
    "Design": "Design",
    "Sliding Window": "Sliding-Window",
    "Backtracking": "Backtracking",
    "Recursion": "Recursion",
    "Linked List": "Linked-Lists",
    "Trie": "Trie",
    "Queue": "Queue",
    "Divide and Conquer": "Divide-and-Conquer",
    "Number Theory": "Number-Theory",
    "Geometry": "Geometry",
    "Randomized": "Randomized",
    "Memoization": "Memoization",
}

_cache: dict = {}
_cache_file = Path(__file__).parent / ".topic_cache.json"


def load_cache():
    global _cache
    if _cache_file.exists():
        try:
            _cache = json.loads(_cache_file.read_text())
        except Exception:
            _cache = {}


def save_cache():
    _cache_file.write_text(json.dumps(_cache, indent=2))


def fetch_topic(title_slug: str) -> str:
    """Return the canonical folder name for a problem slug."""
    if title_slug in _cache:
        return _cache[title_slug]

    payload = json.dumps({"query": QUERY, "variables": {"titleSlug": title_slug}}).encode()
    req = urllib.request.Request(
        GRAPHQL_URL,
        data=payload,
        headers={
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0",
            "Referer": "https://leetcode.com",
        },
    )
    try:
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read())
        tags = [t["name"] for t in data.get("data", {}).get("question", {}).get("topicTags", [])]
        # Pick the highest-priority tag
        for t in TOPIC_ORDER:
            if t in tags:
                folder = TOPIC_ALIASES.get(t, t.replace(" ", "-"))
                _cache[title_slug] = folder
                save_cache()
                return folder
        folder = TOPIC_ALIASES.get(tags[0], tags[0].replace(" ", "-")) if tags else "Uncategorized"
        _cache[title_slug] = folder
        save_cache()
        return folder
    except Exception as e:
        print(f"  [warn] could not fetch tags for {title_slug}: {e}")
        _cache[title_slug] = "Uncategorized"
        save_cache()
        return "Uncategorized"


def slug_from_folder(name: str) -> str:
    """Extract title-slug from folder name like '1-two-sum' → 'two-sum'."""
    return re.sub(r"^\d+-", "", name)


def padded_folder(name: str) -> str:
    """Zero-pad the question ID: '1-two-sum' → '0001-two-sum'."""
    m = re.match(r"^(\d+)-(.+)$", name)
    if m:
        return f"{int(m.group(1)):04d}-{m.group(2)}"
    return name


def main():
    if not SOLUTIONS_DIR.exists():
        print("No solutions/ directory found.")
        sys.exit(0)

    load_cache()

    # Collect all flat problem folders (skip already-organized topic folders)
    problem_dirs = []
    for entry in sorted(SOLUTIONS_DIR.iterdir()):
        if entry.is_dir() and re.match(r"^\d+-", entry.name):
            problem_dirs.append(entry)

    if not problem_dirs:
        print("No flat problem folders found — already organized or empty.")
        sys.exit(0)

    print(f"Found {len(problem_dirs)} problem folder(s) to organize.\n")
    moves: list[tuple[Path, Path]] = []

    for i, pdir in enumerate(problem_dirs, 1):
        slug = slug_from_folder(pdir.name)
        topic = fetch_topic(slug)
        dest = SOLUTIONS_DIR / topic / padded_folder(pdir.name)
        print(f"[{i:3d}/{len(problem_dirs)}] {pdir.name}  →  {topic}/{padded_folder(pdir.name)}")
        moves.append((pdir, dest))
        # Gentle rate-limit — LeetCode throttles aggressive scrapers
        if i % 10 == 0:
            time.sleep(1)

    if not APPLY:
        print(f"\nDry run — {len(moves)} move(s) planned. Re-run with --apply to execute.")
        return

    print(f"\nApplying {len(moves)} move(s)...")
    for src, dst in moves:
        dst.parent.mkdir(parents=True, exist_ok=True)
        if dst.exists():
            # Merge: move files individually to avoid overwriting a pre-existing folder
            for f in src.iterdir():
                target = dst / f.name
                if not target.exists():
                    shutil.move(str(f), str(target))
            if not any(src.iterdir()):
                src.rmdir()
        else:
            shutil.move(str(src), str(dst))

    print("Done. solutions/ is now organized by topic.")


if __name__ == "__main__":
    main()
