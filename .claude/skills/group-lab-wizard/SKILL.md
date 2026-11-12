---
name: group-lab-wizard
description: >-
  Phase-aware wizard for the CSC-240 Group Lab (Collaborative Data Structure Project,
  50 pts). Reads the Group Lab PDF and the Course Schedule PDF, reconciles their
  deadlines, works out which phase the group is in from today's date, and interviews
  Adrian for exactly what that phase's rubric items need. It then assembles his answers
  into shareable docs (proposal, kickoff/setup checklist, weekly Group Log entry,
  transcript plan and check, CFF doc, specifications doc, AI disclosure, defense quiz)
  and keeps a running tracker. Use when Adrian says "group lab", "group lab wizard",
  "proposal", "group log", "where are we on the group lab", "what's due for the group",
  "prep the spec doc", "check our repo", or "defense prep". It organizes the group's
  own answers. It never writes the project's C++ and never invents design decisions.
---

# Group Lab Wizard

Set every group member up to earn full rubric credit **and** to survive the individual
defense at Major Oral Inquiry 2. The wizard asks; the group decides; the wizard writes
down what the group decided in the shape the rubric wants.

## Hard rules

1. **No project code.** This follows `csc240/CLAUDE.md`: no `.h`/`.cpp`, no class
   skeletons, no function bodies, no pseudo-code close enough to paste. If Adrian asks for
   code, say this skill can't do that and offer a concept question or a review in words.
2. **No invented content.** Topic, structures, classes, invariants, reflections and
   critical-thinking answers come from Adrian's answers, quoted or lightly tidied. When an
   answer is missing, leave `**TODO(group):** <what's needed>` in the draft. Don't fill it
   in. Helping the group *decide* is allowed, as long as it happens through questions
   (what operations dominate? what's removed, and who still points at it?), never
   through a recommendation.
3. **Disclose everything.** Every time the wizard drafts, restructures or checks
   something, append a row to the tracker's **AI Disclosure Log** (date, tool, what was
   asked, what was done with the output). That log becomes `GroupLab_AIDisclosure.pdf`.
   Undisclosed AI use is an academic-integrity matter. Disclosure costs nothing.
4. **Read-only on the group repo.** Repo audits use `gh` read calls only. Never push,
   comment, open PRs, or change settings.

## Sources (read them, don't copy them)

- Group Lab PDF: `csc240/group_lab/Group Lab_ Collaborative Data Structure Project (50 pts) - CSC-240-0C1 - C++ Data Structures.pdf`
- Course Schedule PDF: `csc240/Course Schedule - CSC-240-0C1 - C++ Data Structures.pdf`
- Submission rules: `~/Downloads/How to Submit Your Work - CSC-240-0C1 - C++ Data Structures.pdf`
  (via **check-submission**)

Extract them with `pdftotext -layout <pdf> -`. Rubric text, templates, critical-thinking
prompts and the seed prompt all come from the Group Lab PDF at run time. Don't paste
them into this skill, because the instructor may revise the PDF.

## State: `docs/GroupLab_Tracker.md` in the group repo

The tracker and every wizard output live in the group repo checkout at
`csc240/group_lab/CSC240GroupLab/docs/`, so teammates see the same state. That checkout is
currently Adrian's fork (`origin` = frimmy, `upstream` = KokaKolaBeans). Changes reach
the group like any other change. Before editing, sync `main` from `upstream` and cut a
`feature-*` branch, then commit as Adrian and open a PR for a teammate to review. Ask
before pushing or opening the PR. Pull before reading, because a teammate may have
updated the tracker. Never put the course PDFs in the repo: it's public, and the PDFs
are the instructor's.

Create the tracker on the first run with these sections, in this order:

1. **Timeline**: a table of every dated item from *both* PDFs: item, Group Lab PDF date,
   Schedule date, **Plan-to date** (the earlier of the two), status (⬜/🟡/✅/🔴 overdue).
   Put ⚠️ on any row where the dates differ, and add one line per conflict to *Open
   questions for instructor*. Include schedule-only items such as the **Design document
   (Nov 29, ≥24h before your MOI2 slot)** and MOI2 booking opening.
   Store the PDFs' modification times. If either PDF has changed since then, re-extract
   it, diff the dates, and point out what moved.
2. **Team**: name, last name (for the zip name), GitHub handle, role/areas, contact.
3. **Infrastructure**: channel, repo URL, board URL, branch-protection agreement, style
   agreement link.
4. **Project**: topic #, problem statement, structures → operation each serves, the two
   (or more) classes and what each represents, ownership/removal answers.
5. **Phase status**: one checklist per phase (see `phases.md`).
6. **Group Log**: a grid of week × member (✅ submitted / ⬜), with Adrian's entries linked.
7. **Decisions & changes from proposal**: dated. This feeds spec §7 and §8.
8. **Open questions for instructor**
9. **AI Disclosure Log**

## Each run

1. **Load or init.** Read the tracker. If it's missing, extract both PDFs, build the
   Timeline, and start with Phase 0.
2. **Status board.** Print a compact board: today's date, current week, next 3
   deadlines with days left, anything 🔴 overdue, ⚠️ conflicts still unresolved, and
   Group Log gaps.
3. **Pick the phase.** Recommend the phase for today's date, using the Plan-to dates and
   the phase windows in `phases.md`. Let Adrian confirm or jump to another phase with
   AskUserQuestion. Overdue items from earlier phases come first.
4. **Interview.** Run that phase's script from `phases.md`. Use AskUserQuestion for
   choices (at most 4 questions per call, recommended option first only when the rubric
   clearly favors it). Use plain chat for open answers. Ask only for what's still
   missing from the tracker, and never re-ask an answered question unless Adrian wants
   to change it. If he does change it, log the change under *Decisions*.
5. **Write outputs** to the group repo's `docs/` (logs in `docs/logs/`) on a feature
   branch. Use Markdown, so the file can also be pasted into the group chat. Name files as listed in
   `phases.md`. When a final PDF is needed, `pandoc file.md -o ~/Downloads/<name>.pdf`.
6. **Update the tracker**, including the disclosure row.
7. **Close** with: what was produced (paths), what's still TODO(group), the next deadline,
   and one *defense-readiness* question about a part of the project Adrian didn't
   write. The whole project is fair game at MOI2.

## Repo health check (any phase, once a repo URL exists)

Rubric §1 is scored "from the repository, not self-report." With `gh` (read-only), report:

- **1.1 Workflow:** commits on `main` that didn't come through a merged PR (compare
  `gh api repos/{o}/{r}/commits?sha=main` with merged PR merge commits), and whether
  branch protection is enabled. Branch names that don't follow `feature-*`/`fix-*`.
- **1.2 Review:** merged PRs with no review or only trivial review comments ("LGTM").
  Flag PRs where the author merged without a teammate's review.
- **1.3 Balance:** commits and merged PRs per author. Commits made under an account
  nobody on the team recognizes, or everything under one account.
- **Branch age:** open branches older than ~7 days. The lab warns that these produce
  conflicts nobody can resolve.

Describe the findings in words with counts and links. Fixes are the group's to make.

## Handoffs

- Final packaging → run **check-submission** (zip naming `GroupLab_Last1_Last2_Last3.zip`,
  clean-folder compile).
- The Group AI transcript is checked by this skill against the *group* criteria in the
  Group Lab PDF, because they differ from the individual transcript rubric. Run
  **check-transcript** too only if Adrian asks.
