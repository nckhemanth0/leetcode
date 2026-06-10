#!/usr/bin/env bash
set -euo pipefail

# ---------------------------------------------------------------------------
# Sync ALL accepted LeetCode submissions into ./solutions, organized per
# problem. Uses leetcode-export (https://github.com/NeverMendel/leetcode-export)
#
# Setup (one time):
#   cp .env.example .env   # then paste your cookies into .env
#   python3 -m venv .venv && source .venv/bin/activate
#   pip install leetcode-export
#
# Run:
#   ./sync.sh
# ---------------------------------------------------------------------------

cd "$(dirname "$0")"

if [[ -f .env ]]; then
  set -a
  # shellcheck disable=SC1091
  source .env
  set +a
fi

if [[ -z "${LEETCODE_SESSION:-}" || -z "${CSRF_TOKEN:-}" ]]; then
  echo "ERROR: LEETCODE_SESSION and CSRF_TOKEN must be set in .env"
  echo "Copy .env.example to .env and paste your cookies."
  exit 1
fi

if ! command -v leetcode-export >/dev/null 2>&1; then
  echo "ERROR: leetcode-export not found. Install it with:"
  echo "  python3 -m venv .venv && source .venv/bin/activate && pip install leetcode-export"
  exit 1
fi

# Folder name template: 0075-sort-colors ; file template keeps the slug.
leetcode-export \
  --cookies "LEETCODE_SESSION=${LEETCODE_SESSION}; csrftoken=${CSRF_TOKEN}" \
  --folder "solutions" \
  --only-accepted \
  --problem-folder-name "{question_frontend_id:04}-{title_slug}" \
  --problem-statement-filename "README.md" \
  --submission-filename "{title_slug}.{extension}"

echo "✅ Sync complete. Review ./solutions, then commit & push."
