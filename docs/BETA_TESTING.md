# MESUT PS4 STORE — Testing & Feedback

Thank you for helping validate MESUT PS4 STORE. This is a real product-development project, and reports from actual hardware are valuable. Please be precise: a successful automated build does **not** prove that a package installs or runs correctly on a PS4.

## Current testing status

The project is under active development. The team will announce a public test build here only after a CI package has been produced and its artifact has been checked. Until that announcement, there is no claim that a downloadable build is ready for console testing.

Check:
- [Latest build workflow](https://github.com/manou23/MESUT-PS4-STORE/actions/workflows/build-ps4.yml)
- [Published releases](https://github.com/manou23/MESUT-PS4-STORE/releases)
- [Open bug reports and test feedback](https://github.com/manou23/MESUT-PS4-STORE/issues)

## Before testing

1. Download only a build linked from this repository's Releases or from a specifically announced test instruction.
2. Verify that the release notes identify the exact version and commit.
3. Read the installation notes and compatibility statement for that build.
4. Back up important console data and understand the risks of running unofficial homebrew.
5. Do not install packages from unknown mirrors or disable security protections to make an unverified package work.

## Suggested test checklist

- [ ] Package downloads completely and has the expected file size.
- [ ] Package installs without an error.
- [ ] App launches and exits cleanly.
- [ ] Main screen renders at the expected TV resolution.
- [ ] D-pad, Cross, Circle, and other documented controls behave correctly.
- [ ] Lists scroll and focus remains visible.
- [ ] Details screen opens and returns correctly.
- [ ] No freeze, crash, or unexpected return to the PS4 menu during the test.
- [ ] Language, text, and layout remain readable at normal TV distance.

Only mark items you actually tested. If a feature is not present in that build, mark it as not tested or not available in your report.

## Submit feedback

Use one of the structured forms:
- [Report a bug](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=bug_report.yml)
- [Submit a real-console test report](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=field_test_report.yml)
- [Suggest a feature](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=feature_request.yml)

A useful report includes the exact build/commit, console model, firmware, homebrew environment, steps, expected result, actual result, and relevant error text.

## Privacy and safety

Never publish PSN credentials, account identifiers, console serial numbers, device IDs, private tokens, private package URLs, or personal files. Remove such information from screenshots and logs. Do not upload copyrighted game packages or game data as issue attachments.

## What happens after submission?

Reports are reviewed, categorized, and may be followed up with questions. Reproducible issues help prioritize fixes. A suggestion is not a promise that a feature will be implemented, and test reports are not endorsements or proof of compatibility beyond the exact setup reported.
