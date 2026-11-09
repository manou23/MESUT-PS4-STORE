<div align="center">

# 🎮 MESUT PS4 STORE

**A PlayStation Store-inspired homebrew library for PS4**

[![Version](https://img.shields.io/badge/version-1.0.0-0070d1?style=for-the-badge)](CHANGELOG.md)
[![Platform](https://img.shields.io/badge/platform-PS4-111111?style=for-the-badge&logo=playstation)](#)
[![Language](https://img.shields.io/badge/language-Arabic%20%7C%20English-16a34a?style=for-the-badge)](#)
[![License](https://img.shields.io/badge/license-MIT-64748b?style=for-the-badge)](LICENSE)

*Discover, organize, and manage homebrew and legally distributable packages from your PS4.*

</div>

---

## ✨ Vision

MESUT PS4 STORE is being built as a native PS4 homebrew application with a polished, console-first interface inspired by the PlayStation Store: dark surfaces, PlayStation-blue highlights, large cover art, horizontal shelves, fast search, and clear package details.

### Planned experience
- **Console-native interface** designed for TV screens and DualShock 4 navigation.
- **Arabic and English** interface with right-to-left layout support.
- **Curated library** with separate sections for Homebrew, Tools, Themes, and other permitted content.
- **Search, filters, favorites, and recently viewed items.**
- **Package details** including version, size, compatibility notes, screenshots, and verified publisher/source.
- **Safe package workflow**: show provenance and integrity information before a user chooses to install a package.

## 📦 Content sources and rights

The project has been asked to examine [PSPKG](https://pspkg.com/) as a possible catalogue reference. Its public pages list many commercial game titles and PKG downloads. This project will **not mirror, scrape, redistribute, or link to unauthorized copies of commercial games**, bypass access controls, or automate downloads from protected pages.

The initial store will support:
1. Homebrew and tools whose authors permit redistribution.
2. Packages supplied by the user or an authorized publisher.
3. Public catalogue metadata only where its use is permitted; metadata does not imply permission to download a game.

A listing must have a traceable source and a clear redistribution/usage status before it can expose a package action.

## 🧱 Project status

**Current release line: 1.0.0 — foundation**

| Area | Status |
|---|---|
| Product architecture and content policy | In progress |
| Catalogue data format | Added |
| Native PS4 UI | Planned |
| Arabic / English localization | Planned |
| Search, categories, favorites | Planned |
| Authorized package handling | Planned |
| OpenOrbis build and PKG validation | Not yet verified |

> This repository is an early foundation, not yet an installable PS4 PKG. A PKG will only be announced after a successful build and artifact verification.

## 🛠️ Technology direction

- **Target:** PS4 homebrew.
- **Toolchain:** [OpenOrbis PS4 Toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain).
- **Native UI direction:** SDL2-based interface, subject to toolchain and device testing.
- **Catalogue:** versioned JSON manifest with explicit source and rights metadata.
- **Build:** GitHub Actions once the toolchain and packaging pipeline are validated.

## 📁 Repository map

```
.
├── .github/workflows/
├── assets/README.md
├── data/catalog.json
├── docs/
│   ├── ARCHITECTURE.md
│   ├── CONTENT_POLICY.md
│   └── ROADMAP.md
├── src/README.md
├── CHANGELOG.md
├── CONTRIBUTING.md
├── LICENSE
└── README.md
```

## 🚀 Releases

Release packages will appear in [GitHub Releases](https://github.com/manou23/MESUT-PS4-STORE/releases) only after the build has passed validation. Do not install unofficial files from third-party mirrors.

## ⚠️ Compatibility

This is homebrew software. Compatibility depends on the PS4 firmware, the jailbreak/homebrew environment, and the final build configuration. No firmware compatibility is claimed until tested on real hardware.

## 🤝 Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for code, catalogue, security, and localization guidelines.

---

<div align="center">

**MESUT PS4 STORE · Built for the homebrew community**

</div>
