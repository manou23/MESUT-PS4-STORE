# Brewology PS4 Homebrew catalogue integration

## Current integration

Brewology's PS4 games directory is the curated external discovery source used for the project's homebrew listings:

- Catalogue: https://store.brewology.com/ps4/games/
- Integration mode: curated metadata and upstream listing links.
- Direct package downloads in MESUT PS4 STORE: disabled pending verification of redistribution rights for each package.
- Commercial titles: use official publisher or PlayStation Store references, not third-party PKG mirrors.

The catalogue records selected public listing metadata such as title, version, developer, package format, release status, and whether separate original game data is required. The app should direct users to the canonical upstream listing for current package information.

## Game data and redistribution

A homebrew engine port may still require proprietary data files from a user's own legally obtained copy. The presence of a PKG on an external listing does not mean the game data can be redistributed.

Before enabling an in-app download for an entry, verify:
1. The package's publisher or maintainer explicitly permits redistribution or direct linking.
2. Any required game data is separately identified and is not bundled without permission.
3. The upstream file is still available and matches the listed version.
4. HTTPS source attribution, file size, and SHA-256 are recorded where available.

## Commercial game discovery

Commercial PS4 titles are listed separately as discovery entries using official PlayStation Store pages. These records are not package mirrors and must not expose unauthorized commercial PKG downloads.

## Catalogue fields

Entries may include:

- `id`: stable catalogue identifier.
- `title`, `developer`, `version`, `platform`, and `format`.
- `listing_url`: canonical upstream listing.
- `requires_user_game_data`: whether original game data is required.
- `download_mode`: current download behavior.
- `direct_download_enabled`: enabled only after redistribution rights are verified.
- `source_id`: identifier of the source record in `data/catalog.json`.
