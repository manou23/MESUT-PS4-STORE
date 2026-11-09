# Changelog

All notable changes to MESUT PS4 STORE are documented here.

## [1.0.1] - 2026-11-09

### Added
- Runtime JSON catalogue reader for the bundled PS4 manifest.
- Package-root catalogue file included in the GP4 file list.
- Dedicated screens for all five home categories, with clear status text for features not yet active.
- Manifest validation and generated C++ fallback title arrays.

### Fixed
- Corrected the runtime manifest path to match the package-root layout.
- Avoided GP4 nested-directory generation that caused the package builder to fail.

### Validation
- The 1.0.0 package-root build passed PKG validation and uploaded successfully.
- The 1.0.1 build is in progress; console installation and runtime behavior remain unverified.

## [1.0.0] - 2026-11-09

### Added
- Redesigned the README as a branded project landing page with a dedicated latest-release download area.
- Added release, workflow, changelog, and issue navigation links.
- Registered PSPKG as an external catalogue reference without enabling unauthorized direct downloads.
- Added seven curated PS4 homebrew game records from Brewology, with versions, formats, requirements, and external listing links.
- Added a commercial PS4 discovery shelf with 12 real retail titles, including EA SPORTS FC 27 and its free Lite preview, using official PlayStation Store references.
- Added native controller-browsable Retail Games and Homebrew Games screens with title detail panels.
- Corrected the SDL2 cross-build unwind flag for compatibility with Ubuntu Clang 14.
- Recorded whether each title needs separately obtained game data; kept direct third-party package downloads disabled pending rights verification.
- Added PSPKG integration notes and clarified third-party content authorization rules.
- Corrected the OpenOrbis SDK extraction root and added package-tool setup to CI.
- Professional project documentation.
- Native C++ / SDL2 store interface foundation.
- TV-first 1920×1080 layout with featured banner and category tiles.
- Keyboard and joystick navigation foundation.
- OpenOrbis Makefile and PS4 package metadata generation steps.
- GitHub Actions workflow for toolchain setup, SDL2 build, PKG packaging, and artifact upload.
- Versioned catalogue manifest and content rights policy.

### In progress
- Automated native build and PKG validation.
- Controller mapping validation.
- Arabic RTL font rendering and localization.
- Catalogue loading, search, and authorized package handling.

### Notes
- The PKG is not declared ready until the workflow succeeds and the artifact is checked.
- Real-console installation and firmware compatibility are not yet verified.
