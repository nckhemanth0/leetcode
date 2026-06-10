# AGENTS.md — LeetCode sync

Repo: `nckhemanth/leetcode-sync` · Auto-synced LeetCode submission mirror.

## Purpose

Machine-synced dump of all accepted LeetCode submissions. **Not** the curated `leetcode` repo (name reserved for future writeups).

## Sync methods

| Method | Command / trigger |
|--------|-------------------|
| Local | `./sync.sh` (needs `.env` with cookies) |
| CI | `.github/workflows/sync.yml` — daily 6 AM UTC |
| Post-sync | `python3 organize.py --apply` — topic folders |

## Secrets (names only)

- `LEETCODE_SESSION`, `CSRF_TOKEN` — GitHub Actions secrets + local `.env`
- Never commit `.env`

## Dependencies

- `leetcode-export` (pip)
- Cookies expire every few weeks — refresh secrets when sync fails

## After changes

- Append to hub `context/common/CHANGELOG.md`
- Commit only when user asks
- CI: workflow does `git pull --rebase` before push

## Redirect

`github.com/nckhemanth/leetcode` → `leetcode-sync` (legacy repo name)
