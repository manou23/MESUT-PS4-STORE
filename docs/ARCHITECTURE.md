# Architecture

## Product layers

1. **Presentation** — native PS4 UI, designed for 1080p television viewing and controller-first navigation.
2. **Catalogue** — local, versioned JSON manifest. The UI must remain usable when the network is unavailable.
3. **Source adapter** — retrieves only approved catalogue metadata from documented, permitted sources.
4. **Package service** — handles only packages that the publisher or user is authorized to distribute/install.
5. **Integrity and provenance** — displays publisher, source, version, file size, checksum when supplied, and compatibility notes.

## Catalogue item contract

Each item should define:
- `id`: stable unique identifier.
- `title`: localized title object.
- `category`: homebrew, tool, theme, or application.
- `description`: localized description object.
- `version`: release version.
- `platform`: target platform.
- `icon` / `cover`: optional artwork references with permission to use.
- `source_url`: canonical publisher/source page.
- `package_url`: optional direct package URL, only when redistribution is explicitly authorized.
- `license`: license identifier or rights statement.
- `sha256`: optional integrity digest.
- `min_firmware` / `max_firmware`: optional tested compatibility range.

## UI navigation

- Home
- Homebrew
- Tools
- Themes
- Search
- Favorites
- Downloads / package queue
- Settings (language, network, display)

## Offline-first behavior

The catalogue is cached locally. Network errors must not freeze navigation. Every download action must expose progress, pause/cancel where supported, and a clear error state.

## Native implementation

The target is a native PS4 homebrew executable built with OpenOrbis. SDL2 is the current UI direction, pending dependency and hardware validation. HTML-only output is not considered a PS4 PKG.
