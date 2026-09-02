// Copyright 2024-2026 The Khronos Group Inc.
//
// SPDX-License-Identifier: Apache-2.0

import {
  removeBreakNamespace,
  fixFonts,
  removeDrawioAttrs,
  removeForeignObject,
} from "./svgo-plugins.mjs";

export default {
  multipass: true,
  plugins: [
    fixFonts,
    "preset-default",
    removeDrawioAttrs,
    fixFonts,
    removeBreakNamespace,
    removeForeignObject,
  ],
};
