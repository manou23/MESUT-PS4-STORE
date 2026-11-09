# PSPKG source integration

## Current integration

PSPKG is registered in `data/catalog.json` as an **external catalogue reference**:

- Homepage: https://pspkg.com/
- In-app direct package download: disabled.
- Automated metadata import: disabled until a documented, authorized API or written permission is verified.
- Protected download pages, subscription checks, anti-bot controls, and authentication are not automated or bypassed.

This provides a safe starting point: the app can identify PSPKG as an external source and direct users to its website, while keeping the native catalogue independent.

## Why direct game downloading is not enabled

PSPKG's public terms state that its content and software are protected and may not be copied, distributed, or modified without written permission. The site also offers subscription-gated features. A game listing does not establish that its publisher authorized redistribution.

References:
- [PSPKG Terms and Conditions](https://pspkg.com/ar/terms-and-conditions/)
- [PSPKG website](https://pspkg.com/)

## How an authorized integration can be enabled

If PSPKG provides a documented public API, feed, or written permission for the intended integration, add a source adapter that:
1. Fetches only the documented public metadata endpoint.
2. Parses title, platform, version, artwork URL, and canonical item page.
3. Stores source attribution and retrieval timestamp.
4. Keeps the download action disabled unless the package publisher authorizes distribution or direct linking.
5. Validates HTTPS, expected hostnames, file size, and SHA-256 before accepting an authorized package.

## Package manifest fields

Authorized downloadable entries may use:

- `id`: stable catalogue identifier.
- `title`: display title.
- `platform`: target platform.
- `version`: package version.
- `source_name` and `source_page`: provenance.
- `download_url`: only when distribution is authorized.
- `sha256`: integrity digest when available.
- `license` and `redistribution_permission`: rights information.

Do not populate `download_url` from a commercial listing unless permission is verified.
