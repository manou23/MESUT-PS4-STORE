<div align="center">

# 🎮 MESUT PS4 STORE

### YOUR CONSOLE. YOUR LIBRARY. YOUR EXPERIENCE.

**A native, controller-first homebrew library for PlayStation 4**

[![Version](https://img.shields.io/badge/version-1.0.2-0878D1?style=for-the-badge)](CHANGELOG.md)
[![Platform](https://img.shields.io/badge/platform-PLAYSTATION%204-151B2B?style=for-the-badge)](#)
[![Build](https://img.shields.io/github/actions/workflow/status/manou23/MESUT-PS4-STORE/build-ps4.yml?branch=main&style=for-the-badge&label=BUILD)](https://github.com/manou23/MESUT-PS4-STORE/actions/workflows/build-ps4.yml)
[![License](https://img.shields.io/badge/license-MIT-2E9D69?style=for-the-badge)](LICENSE)

[**⬇ DOWNLOAD LIBRARY**](https://github.com/manou23/MESUT-PS4-STORE/releases/latest)　|　[BUILD STATUS](https://github.com/manou23/MESUT-PS4-STORE/actions)　|　[CHANGELOG](CHANGELOG.md)

</div>

---

## ✦ About the project

**MESUT PS4 STORE** is being developed as a dedicated PS4 homebrew library, designed around the comfort of the television screen and DualShock 4 controller. Its visual direction takes inspiration from the PlayStation Store: deep midnight surfaces, electric-blue highlights, featured content panels, and clean category shelves.

The goal is to bring discovery, organization, and authorized package management together in one native console experience. The current native UI includes controller-browsable Retail Games and Homebrew Games shelves. The native app includes a runtime JSON catalogue reader for the bundled manifest at `/app0/catalog.json`. Persistent favorites have been added and the native package build passed in GitHub Actions. Real-console behavior still needs testing.

## ↓ Download MESUT PS4 STORE

<div align="center">

### MESUT PS4 STORE · Latest Release

**The official download area for published PKG builds**

[![Get the latest version](https://img.shields.io/badge/GET%20THE%20LATEST%20PKG-OPEN%20DOWNLOADS-0878D1?style=for-the-badge&logo=playstation)](https://github.com/manou23/MESUT-PS4-STORE/releases/latest)

[Open all releases](https://github.com/manou23/MESUT-PS4-STORE/releases) · [View automated build artifacts](https://github.com/manou23/MESUT-PS4-STORE/actions/workflows/build-ps4.yml)

> **Release availability:** The download link above always points to the latest GitHub Release. A PKG is not considered ready until a build has succeeded and its package has been checked. Until then, the page may show that no stable release is published.

</div>

## ✨ Experience & features

| Feature | Development status |
|---|---|
| Native PS4 application foundation | CI build successful; real-console test pending |
| TV-first 1920 × 1080 interface | Initial UI added |
| DualShock 4 navigation | Basic input foundation added |
| Retail PS4 game discovery shelf | 12 curated titles generated from catalogue manifest |
| Homebrew games shelf | 7 curated titles generated from catalogue manifest |
| Controller-browsable game lists and detail panels | Initial native screens added |
| Runtime JSON catalogue reader and PKG manifest bundling | Implemented; CI build passed |
| Runtime JSON catalogue browsing | Implemented; CI build passed |
| Persistent favorites (save/remove and Favorites shelf) | Implemented; CI build passed, console test pending |
| Search and filters | Planned |
| Favorites and authorized download queue | Planned |
| Arabic RTL + English interface | Planned |
| Authorized PKG download manager | Planned |
| Package verification and integrity checks | Planned |

## 🧭 Content sources

### Brewology PS4 Homebrew catalogue

[![Browse PS4 Homebrew](https://img.shields.io/badge/BREWOLOGY-PS4%20HOMEBREW%20GAMES-26364F?style=for-the-badge)](https://store.brewology.com/ps4/games/)

Brewology is the curated external source currently used for the project's PS4 homebrew game listings. MESUT PS4 STORE includes selected game metadata and links to each upstream listing, including version, package format, developer, and whether separate original game data is required.

The commercial-game discovery shelf uses official [PlayStation Store](https://store.playstation.com/) references for titles such as EA SPORTS FC 27, Grand Theft Auto V, Red Dead Redemption 2, and God of War Ragnarök. These are discovery links, not third-party PKG download sources.

**Direct package downloads inside MESUT PS4 STORE will be enabled only for homebrew, publisher-authorized files, or packages supplied by users who have the necessary rights.** A listing or a working PKG on modified hardware does not by itself establish permission to redistribute a commercial game.

Read the [AI self-repair architecture](docs/AI_SELF_REPAIR.md), [content and source policy](docs/CONTENT_POLICY.md) and [Brewology integration notes](docs/BREWOLOGY_INTEGRATION.md).
## 🎨 Design direction

- Midnight navy interface with PlayStation-blue accents.
- Large featured area and clear content shelves.
- Focus states designed for controller navigation.
- Readable typography and consistent spacing.
- Arabic right-to-left and English left-to-right layouts as the language system is implemented.

## 🧱 Technology

- **Application:** C++
- **Rendering and input:** SDL2
- **PS4 homebrew toolchain:** [OpenOrbis PS4 Toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain)
- **Build automation:** GitHub Actions
- **Catalogue format:** Versioned JSON manifest

## 📦 Project structure

```
.
├── .github/workflows/       # Automated PS4 build
├── app/                     # Native PS4 application
│   ├── MESUTPS4Store/
│   ├── sce_sys/
│   └── Makefile
├── data/
│   └── catalog.json         # Catalogue manifest
├── docs/
│   ├── ARCHITECTURE.md
│   ├── CONTENT_POLICY.md
│   ├── BREWOLOGY_INTEGRATION.md
│   └── ROADMAP.md
├── assets/
├── CHANGELOG.md
├── CONTRIBUTING.md
└── LICENSE
```

## 🛠️ Build status

Every code change can be built through [GitHub Actions](https://github.com/manou23/MESUT-PS4-STORE/actions/workflows/build-ps4.yml). Successful workflow artifacts are temporary CI outputs; stable user downloads will be published through GitHub Releases after validation.

**Current package version:** 1.0.2 — development build. Local diagnostic logging is implemented; cloud AI-assisted repair is designed but not yet connected to a deployed backend.

- [View latest workflow run](https://github.com/manou23/MESUT-PS4-STORE/actions)
- [Download published releases](https://github.com/manou23/MESUT-PS4-STORE/releases)
- [Report a build issue](https://github.com/manou23/MESUT-PS4-STORE/issues)

## ⚠️ Compatibility & installation

This project is intended for compatible PS4 homebrew environments. Firmware compatibility, installation behavior, and controller support must be verified on real hardware before being advertised as supported. Do not assume that every modified PS4 firmware is compatible.

## 🗺️ Roadmap

1. Stabilize the OpenOrbis build pipeline and produce a verified PKG.
2. Complete category screens, focus handling, and controller navigation.
3. Implement catalogue parsing, search, and item details.
4. Add an authorized package download queue with progress and integrity checks.
5. Add Arabic shaping/RTL support and English localization.
6. Test installation and runtime behavior on supported PS4 hardware.

## 🧪 Join the tester community

Help us validate MESUT PS4 STORE with clear, reproducible feedback. **Real-console testing is not open until a verified test PKG is announced in Releases or in the testing guide.** A green CI check alone does not mean the app has been tested on a PS4.

<div align="center">

[**🧪 TESTER GUIDE**](docs/BETA_TESTING.md)　|　[**🐞 REPORT A BUG**](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=bug_report.yml)　|　[**💡 SUGGEST A FEATURE**](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=feature_request.yml)　|　[**🎮 SEND TEST RESULTS**](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=field_test_report.yml)

</div>

We welcome feedback about installation, startup, controller navigation, TV readability, performance, catalogue accuracy, and accessibility. Please include the exact build, firmware, environment, and reproduction steps. Never post account credentials, console identifiers, private tokens, or copyrighted game packages.

## 💬 Community Discussions

The MESUT PS4 STORE community is now open on GitHub Discussions. Join the conversation, ask questions, share ideas, and follow project announcements.

<div align="center">

[**💬 OPEN COMMUNITY DISCUSSIONS**](https://github.com/manou23/MESUT-PS4-STORE/discussions)

</div>

Use the discussion categories to keep conversations organized:
- **Announcements** — official project news and release updates.
- **General** — community conversation.
- **Ideas** — feature concepts and product feedback.
- **Q&A** — technical questions and help.
- **Show and tell** — demos, screenshots, and community contributions.

For reproducible defects, please use the [bug report form](https://github.com/manou23/MESUT-PS4-STORE/issues/new?template=bug_report.yml) rather than a general discussion. For security-sensitive reports, follow [SECURITY.md](SECURITY.md).

## 🤝 Contributing

Bug reports, tested fixes, and improvements are welcome. Please read [CONTRIBUTING.md](CONTRIBUTING.md) before submitting changes.

---

<div align="center">

**MESUT PS4 STORE**

*Made for the console. Built for the community.*

[GitHub Repository](https://github.com/manou23/MESUT-PS4-STORE) · [Releases](https://github.com/manou23/MESUT-PS4-STORE/releases) · [Issues](https://github.com/manou23/MESUT-PS4-STORE/issues)

</div>
