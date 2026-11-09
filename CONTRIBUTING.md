# Contributing to MESUT PS4 STORE

Thank you for helping improve MESUT PS4 STORE. We treat this as a maintained product: reproducibility, clear scope, safe distribution, and honest compatibility claims matter.

## Choose the right contribution path

- **Bug or crash:** use the [bug report form](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=bug_report.yml).
- **Real PS4 test result:** use the [field test report](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=field_test_report.yml), and read the [testing guide](docs/BETA_TESTING.md).
- **Feature idea:** use the [feature request form](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=feature_request.yml).
- **Code change:** open a pull request with a focused explanation, implementation notes, and test evidence.

## Engineering guidelines

- Keep the app controller-first and readable from normal TV viewing distance.
- Preserve a clear path for Arabic RTL and English LTR layouts.
- Keep catalogue changes schema-aware and backwards-compatible where practical.
- Keep network operations, downloads, and installation responsive; do not block the render/input loop.
- Validate remote package size and cryptographic integrity before any installation step.
- Never commit credentials, tokens, private URLs, personal data, or console identifiers.
- Include reproducible build instructions and report exactly what was and was not tested.
- Do not claim real-console compatibility based only on a successful CI build.

## Content and package rights

Commercial game discovery references must point to official or otherwise authorized sources. Do not add unauthorized commercial PKG links, copyrighted game files, or game data. Direct package distribution is allowed only when the publisher or rights holder authorizes it, or when the contributor has the necessary rights to distribute the supplied file.

See [CONTENT_POLICY.md](docs/CONTENT_POLICY.md).

## Pull request expectations

1. Keep each pull request focused on one feature or fix.
2. Explain the user problem and the chosen solution.
3. Include screenshots or short recordings for visible UI changes where practical.
4. Include build logs or test output, with secrets removed.
5. Update documentation and changelog entries when behavior or user-facing capabilities change.
6. Do not mark a feature complete if it is only a placeholder or catalogue entry.

## Versioning and releases

- Patch: fixes, reliability improvements, and documentation corrections.
- Minor: backwards-compatible user-facing capabilities.
- Major: breaking architecture or catalogue changes.

A release is ready only after the package artifact has been produced, checked, and its stated compatibility has been validated to the level claimed in the release notes.
