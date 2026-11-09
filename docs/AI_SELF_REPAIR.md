# MESUT AI Self-Repair — architecture and safety

## Current implementation (1.0.2 development build)

The PS4 client now writes a local diagnostic log to:

`/data/mesut_ps4_store_diagnostics.log`

It records startup, SDL initialization/window/renderer failures, catalogue loading counts or a missing catalogue manifest, favorite persistence failures, favorite changes, and normal shutdown.

The Tools screen explains that diagnostics are local. No telemetry is uploaded automatically, and the log may contain device/runtime details; users must review it before sharing.

## What is not active yet

There is no embedded ChatGPT model, remote AI endpoint, automatic issue submission, or unattended remote code execution in the PS4 client. The diagnostic log is a safe foundation, not an AI repair service.

## Planned cloud-assisted repair flow

1. User explicitly chooses **Send diagnostic report** and reviews the report.
2. Client sends a minimized, redacted report over HTTPS to a separately deployed backend.
3. Backend validates the app version and report schema, removes secrets/identifiers, rate-limits requests, and stores a traceable incident.
4. An AI service classifies the failure and proposes a patch; it never executes arbitrary commands on the console.
5. A maintainer-reviewed change is built in GitHub Actions, with static checks and package validation.
6. The app checks a signed update manifest and offers the update. Installation is user-approved and rollback remains available.

## Required infrastructure

- A deployed HTTPS backend and domain.
- Server-side AI API credentials stored as deployment secrets; never embed API keys in the PS4 PKG.
- A signed update manifest and a trusted signing-key strategy.
- Privacy notice, consent screen, retention policy, abuse protection, and report redaction.
- A maintainer approval gate before any patch is released.

## Security rules

- Never upload PSN credentials, console IDs, account tokens, save data, or package contents.
- Never let model output run as shell commands on the PS4.
- Never install an update solely because an AI suggested it.
- Reject unsigned, mismatched, or downgraded packages unless the user explicitly selects a supported rollback.
- Keep an offline/local-only mode.
