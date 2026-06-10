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

# Why this is slow: leetcode-export fetches your full submission history,
# then makes one API call per problem for the README. ~200 problems ≈ 5–10 min.
# Set FAST_SYNC=1 to skip problem statements (code only, much faster).
EXPORT_FLAGS=(
  --cookies "LEETCODE_SESSION=${LEETCODE_SESSION}; csrftoken=${CSRF_TOKEN}"
  --folder "solutions"
  --only-accepted
  --only-last-submission
  --problem-folder-name '${question_id}-${title_slug}'
  --submission-filename '${title_slug}.${extension}'
  -v
)

if [[ "${FAST_SYNC:-}" == "1" ]]; then
  EXPORT_FLAGS+=(--no-problem-statement)
  echo "⚡ Fast mode: skipping problem statements"
else
  EXPORT_FLAGS+=(--problem-statement-filename 'README.md')
fi

echo "⏳ Syncing LeetCode submissions (this can take several minutes)..."
leetcode-export "${EXPORT_FLAGS[@]}"

COUNT=$(find solutions -mindepth 1 -maxdepth 1 -type d 2>/dev/null | wc -l | tr -d ' ')
echo "✅ Sync complete — ${COUNT} problems in ./solutions"
