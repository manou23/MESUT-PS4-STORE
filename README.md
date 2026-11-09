<div align="center">

# 🎮 MESUT PS4 STORE

**A PlayStation Store-inspired native homebrew library for PS4**

[![Version](https://img.shields.io/badge/version-1.0.0-0070d1?style=for-the-badge)](CHANGELOG.md)
[![Platform](https://img.shields.io/badge/platform-PS4-111111?style=for-the-badge&logo=playstation)](#)
[![Language](https://img.shields.io/badge/language-English%20preview%20%7C%20Arabic%20planned-16a34a?style=for-the-badge)](#)

*Discover, organize, and manage homebrew and authorized packages directly from your console.*

</div>

---

## ✨ Product vision

A native PS4 application with a polished, TV-first interface inspired by the PlayStation Store: dark surfaces, PlayStation-blue accents, large featured panels, category shelves, and DualShock navigation.

### Planned experience
- Native PS4 application, not a web page.
- DualShock 4 navigation and clear focus states.
- Arabic RTL and English LTR interface.
- Separate Homebrew, Tools, Themes, and Applications sections.
- Search, favorites, recent items, and item details.
- Package provenance, version, size, checksum, and compatibility information.
- Download queue for packages the user is authorized to obtain.

## 🧪 Current development status

**Release line: 1.0.0 — native preview foundation**

| Component | Status |
|---|---|
| Repository architecture and policy | Added |
| Native SDL2 interface source | Added |
| Controller input foundation | Added |
| OpenOrbis build workflow | Added; first run in progress |
| Verified installable PKG | Not yet confirmed |
| Arabic RTL rendering | Planned |
| Live catalogue and search | Planned |
| Authorized package queue | Planned |
| Real-console testing | Pending |

The first native screen currently provides a visual store shell and category navigation. The first automated build is being evaluated. This is not yet a verified installable release.

## 📦 Content sources and rights

[PSPKG](https://pspkg.com/) was suggested as a catalogue reference. Its listings may include commercial game packages. A listing does not establish permission to download or redistribute that content.

MESUT PS4 STORE will support:
1. Homebrew and tools whose authors permit distribution.
2. Packages supplied by the user or an authorized publisher.
3. Catalogue metadata and artwork only where their use is permitted.

The app will not mirror unauthorized commercial game packages, bypass DRM, or automate access to protected download pages.

## 🛠️ Technology

- **Native UI:** C++ and SDL2.
- **PS4 toolchain:** [OpenOrbis PS4 Toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain).
- **Build:** GitHub Actions with a reproducible toolchain setup.
- **Catalogue:** versioned JSON manifest with source and rights metadata.

## 📁 Repository structure

```
.
├── .github/workflows/build-ps4.yml
├── app/
│   ├── MESUTPS4Store/main.cpp
│   ├── Makefile
│   └── sce_sys/
├── assets/
├── data/catalog.json
├── docs/
├── src/
├── CHANGELOG.md
├── CONTRIBUTING.md
└── LICENSE
```

## 🚀 Build artifacts

When the GitHub Actions build succeeds, the PKG will be published as a workflow artifact and later attached to a GitHub Release after validation.

[View build workflow](https://github.com/manou23/MESUT-PS4-STORE/actions/workflows/build-ps4.yml) · [View releases](https://github.com/manou23/MESUT-PS4-STORE/releases)

## ⚠️ Compatibility

Compatibility depends on firmware, jailbreak environment, and the final build. No firmware support is claimed until tested on real hardware.

## 🤝 Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md).

---

<div align="center">**MESUT PS4 STORE · Built for the homebrew community**</div>
