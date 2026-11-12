# Phases

Each phase lists: **window** (in terms of Plan-to dates from the tracker Timeline, never
hardcoded), the **rubric items it protects**, the **interview**, and the **outputs**.
Quote rubric and template wording from the Group Lab PDF at run time.

---

## Phase 0: Setup & Proposal
**Window:** now → Proposal date. **Protects:** a required proposal; §1.1 (no direct
commits to main from day one); §4.2 style consistency.

Interview:
1. Team roster: names, last names, GitHub handles. Who creates the repo?
2. Step 1 checklist, one item at a time, each ✅/⬜ with an owner: channel chosen, repo
   created with collaborators added, C++ `.gitignore` committed *before* any code, "no
   direct commits to main" agreed in writing (and is branch protection turned on?), task
   board with To-Do | In Progress | Done | Blocked and named owners, style agreement
   (naming, indentation, comment style, pre/post comment format; point to the Oakton
   C++ Coding Conventions).
3. Topic (1–4 from the PDF table). For the chosen topic, ask what would make it
   "go beyond reimplementing a lab". Use the PDF's quicksort example as the yardstick.
4. Problem statement in 2–3 sentences, in the group's words.
5. Structures → the operation each serves. Then ask the composite-design questions from
   the PDF's Background: who **owns** the data, who only **references** it, what happens
   on **removal**, and where the cost actually lands.
6. The two object classes and what each represents. Does each have one clear
   responsibility (§3.2)?
7. Initial task division by name. Check: does every member touch more than one class or
   layer? Sealed compartments damage individual grades at MOI2. Suggest pairing or
   review rotation as a question, not a mandate.
8. Has anyone tried opening a PR before? If not, schedule the 20-minute trial PR the
   PDF recommends.

Outputs:
- `GroupLab_Proposal.md`: exactly the 5 proposal bullets from the PDF, one page. One
  member submits for the group.
- `GroupLab_Kickoff.md` (for the group channel): timeline with ⚠️ conflicts, Step 1
  checklist with owners, the feature-branch cycle and PR review norm (reviewer asks a
  Tier 1/2 "walk me through this / why this approach?" question; author answers in the
  PR), meeting plan (Week 12 plan & divide, Week 15 integrate & test, both logged),
  and the Group Log template.

---

## Phase 1: Build & weekly Group Log (recurring)
**Window:** each Group Log week from the Timeline (5 entries; note the schedule puts
entries 4 and 5 both in Week 15). **Protects:** Group Log 5 pts; early visibility of
blockers.

Interview (Adrian's entry only; every member submits their own):
1. Meeting date/time, platform, duration. Was this week a required meeting (plan/divide
   or integrate/test)?
2. What I contributed: point to the PRs or commits.
3. What I reviewed or learned from my group: which PR, and what question was asked?
4. Am I blocked? Answer honestly. If yes, add the blocker to the tracker.
5. One thing I'd change about our workflow. Log it to *Decisions*, because it feeds
   critical-thinking Q5.
Then offer the **repo health check** and a reminder ping text for teammates whose log is
⬜.

Outputs: `logs/Week<N>_GroupLog_Frimpong.md` in the PDF's template, and the grid updated.

---

## Phase 2: Group AI Learning Transcript
**Window:** opens after the build starts, through the transcript Plan-to date.
**Protects:** transcript 5 pts and CFF "demonstrates understanding" (the transcript is
the CFF's learning query).

Interview (planning *before* the conversation):
1. Structure A vs. B and the specific operation being decided. Fill in the seed prompt's
   bracketed parts **only**. The rest of the seed prompt stays verbatim from the PDF.
2. Which real code excerpt will you paste? Who brings it?
3. Who will push back, and on what? (The pushback needs visible reasoning.)
4. Who records it, and who writes the closing paragraph? It must say what you decided
   and whether the conversation changed your mind.

Check (after Adrian provides the export): seed prompt verbatim with brackets filled; ≥6
exchanges (counted after the seed); group code embedded; visible pushback with
reasoning; closing paragraph by the group. Cite the exchange number and ≤25 words for each.

Outputs: `GroupLab_TranscriptPlan.md`, then the check results in the tracker.

---

## Phase 3: Creative Final Feature
**Window:** after the transcript, before the Final. **Protects:** CFF 10 pts.

Interview:
1. Which concept from the transcript does the feature use? Quote the exchange.
2. The alternatives the group discussed, and why this one won (CFF Q3).
3. Does it *extend* the working program rather than replace part of it? Was it outside
   the base requirements?
4. Who builds it, and who reviews it? Every member will be asked about it at MOI2.
5. What would you add with two more weeks? (CFF Q4)

Outputs: `GroupLab_FeatureDocumentation.md` with the four questions verbatim from the
PDF, answered in the group's words.

---

## Phase 4: Final package & Design document
**Window:** from Week 15 through the earliest of the Final, Design document, and MOI2
minus 24h. **Protects:** §2, §3, §4, and the deliverables list.

Interview, section by section, against the PDF's nine spec sections and five critical
thinking questions. Pull from the tracker first (Project, Decisions, Team), then ask
only for what's missing. For §5 (class documentation), ask Adrian to paste or point to
the headers. Report which public functions lack pre/postconditions and where styles
differ between members, in words. §2.3 robustness: list the edge cases named in the
critical thinking section, and ask whether the program actually handles each one.

Outputs:
- `GroupLab_Specifications.md` → `~/Downloads/GroupLab_Specifications.pdf`
- `GroupLab_AIDisclosure.md` built from the Disclosure Log plus the group's other AI use
  → PDF
- README checklist (repo URL plus build instructions present? The group writes it.)
- Deliverables table from the PDF, with ✅/⬜ per item
- Then run **check-submission** on the assembled zip.

Ask Adrian whether the schedule's "Design document" is the same as the specifications
document. Log the answer to *Open questions for instructor* until it's confirmed.

---

## Phase 5: Individual defense prep
**Window:** after the Final, through Adrian's MOI2 slot. Also offer a short version
in any phase. **Protects:** the individual accountability adjustment (up to −50%).

Interview: for each class and feature, ask who wrote it and whether Adrian has walked
through it. Then quiz him with one question per component, focused on parts he didn't
write. Use the PDF's question styles: walk me through, why this approach, what happens
on removal, Big-O, 100× scale. Grade each answer Strong/Solid/Partial/Weak against the
PDF's table, and explain the gap in words.

Outputs: `GroupLab_DefenseQuiz.md`, a shareable question set teammates can use to quiz
each other (questions only, no answers).
