#!/usr/bin/env python3
"""Validate the MESUT catalogue and generate compact C++ title arrays."""
import json, pathlib, sys
source, target = pathlib.Path(sys.argv[1]), pathlib.Path(sys.argv[2])
doc = json.loads(source.read_text(encoding='utf-8'))
if doc.get('schema_version') != 2 or not isinstance(doc.get('items'), list): raise SystemExit('Unsupported catalogue schema')
seen, retail, homebrew = set(), [], []
for item in doc['items']:
    required = ('id', 'type', 'title', 'listing_url', 'source_id')
    if any(not isinstance(item.get(k), str) or not item[k].strip() for k in required): raise SystemExit('Missing required catalogue field')
    if item['id'] in seen: raise SystemExit('Duplicate catalogue id: ' + item['id'])
    seen.add(item['id'])
    if not item['listing_url'].startswith('https://'): raise SystemExit('Non-HTTPS listing: ' + item['id'])
    if item.get('direct_download_enabled') is True: raise SystemExit('Unverified direct download: ' + item['id'])
    if item['type'] == 'commercial_game': retail.append(item['title'])
    elif item['type'] == 'game': homebrew.append(item['title'])
    else: raise SystemExit('Unsupported item type: ' + item['type'])
def cpp(x): return json.dumps(x, ensure_ascii=True)
lines = ['// Generated from data/catalog.json. Do not edit by hand.', '#pragma once', 'static const char* retailGames[] = {']
lines += ['    ' + cpp(x) + ',' for x in retail] + ['};', 'static const char* homebrewGames[] = {']
lines += ['    ' + cpp(x) + ',' for x in homebrew] + ['};']
target.parent.mkdir(parents=True, exist_ok=True)
target.write_text('\n'.join(lines) + '\n', encoding='utf-8')
print('Validated %d commercial references and %d homebrew entries' % (len(retail), len(homebrew)))
