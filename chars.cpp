#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

// Karl Yerkes
// 2022-05-27
// Text Experiments on the Linux Console (Raspberry Pi)
//
// Font: /usr/share/consolefonts/Uni3-Terminus32x16.psf.gz
//
// #!/usr/bin/env raku
// "Uni3-Terminus32x16.psf.txt".IO.slurp.split('%')[2..*].map({
//   / "// Character" \s+ $<number>=\d+ / and do {
//     my $hash = .comb.grep('#').elems;
//     $hash / 512;
//   }
// }).join(",").say
//
//

int main() {
  std::vector<float> darkness{
      0.164063, 0.269531, 0.464844, 0.0625,   0.21875,  0.296875, 0.316406,
      0.0625,   0.03125,  0.273438, 0.294922, 0.228516, 0.207031, 0.03125,
      0.097656, 0.203125, 0.023438, 0.021484, 0.1875,   0.132813, 0.234375,
      0.210938, 0.068359, 0.226563, 0.132813, 0.132813, 0.109375, 0.109375,
      0.085938, 0.171875, 0.248047, 0.234375, 0,        0.066406, 0.046875,
      0.21875,  0.25,     0.1875,   0.236328, 0.023438, 0.09375,  0.09375,
      0.152344, 0.085938, 0.025391, 0.046875, 0.015625, 0.078125, 0.25,
      0.117188, 0.1875,   0.191406, 0.177734, 0.189453, 0.207031, 0.132813,
      0.234375, 0.207031, 0.03125,  0.041016, 0.117188, 0.09375,  0.117188,
      0.130859, 0.285156, 0.210938, 0.238281, 0.164063, 0.199219, 0.183594,
      0.144531, 0.203125, 0.1875,   0.109375, 0.136719, 0.1875,   0.117188,
      0.207031, 0.203125, 0.203125, 0.179688, 0.228516, 0.224609, 0.195313,
      0.117188, 0.179688, 0.15625,  0.207031, 0.15625,  0.121094, 0.175781,
      0.117188, 0.078125, 0.117188, 0.058594, 0.046875, 0.023438, 0.175781,
      0.1875,   0.132813, 0.1875,   0.177734, 0.128906, 0.214844, 0.160156,
      0.09375,  0.132813, 0.160156, 0.101563, 0.183594, 0.136719, 0.15625,
      0.183594, 0.183594, 0.099609, 0.15625,  0.128906, 0.136719, 0.109375,
      0.164063, 0.140625, 0.1875,   0.152344, 0.109375, 0.078125, 0.109375,
      0.078125, 0.234375, 0.185547, 0.167969, 0.201172, 0.210938, 0.207031,
      0.199219, 0.214844, 0.154297, 0.212891, 0.208984, 0.201172, 0.109375,
      0.113281, 0.101563, 0.242188, 0.25,     0.207031, 0.214844, 0.257813,
      0.191406, 0.1875,   0.179688, 0.171875, 0.160156, 0.21875,  0.234375,
      0.210938, 0.195313, 0.179688, 0.179688, 0.228516, 0.164063, 0.199219,
      0.101563, 0.179688, 0.160156, 0.1875,   0.253906, 0.171875, 0.15625,
      0.121094, 0.070313, 0.070313, 0.195313, 0.199219, 0.070313, 0.164063,
      0.164063, 0.25,     0.5,      0.246094, 0.125,    0.152344, 0.261719,
      0.207031, 0.21875,  0.214844, 0.132813, 0.132813, 0.144531, 0.140625,
      0.222656, 0.226563, 0.09375,  0.09375,  0.121094, 0.121094, 0.152344,
      0.0625,   0.179688, 0.226563, 0.238281, 0.253906, 0.119141, 0.257813,
      0.203125, 0.203125, 0.214844, 0.144531, 0.179688, 0.226563, 0.210938,
      0.207031, 0.214844, 0.210938, 0.207031, 0.238281, 0.25,     0.125,
      0.09375,  0.09375,  1,        0.078125, 0.253906, 0.216797, 0.216797,
      0.177734, 0.232422, 0.117188, 0.140625, 0.230469, 0.191406, 0.166016,
      0.152344, 0.234375, 0.210938, 0.214844, 0.1875,   0.164063, 0.035156,
      0.050781, 0.140625, 0.140625, 0.132813, 0.140625, 0.140625, 0.125,
      0.125,    0.078125, 0.132813, 0.085938, 0.041016, 0.015625, 0.154297,
      0.091797, 0.103516, 0.210938, 0.050781, 0.023438, 0.023438, 0.023438,
      0.046875, 0.046875, 0.046875, 0.109375, 0.140625, 0.046875, 0.210938,
      0.082031, 0.082031, 0.214844, 0.113281, 0.246094, 0.210938, 0.246094,
      0.210938, 0.1875,   0.15625,  0.199219, 0.167969, 0.234375, 0.222656,
      0.214844, 0.21875,  0.210938, 0.21875,  0.212891, 0.140625, 0.125,
      0.152344, 0.136719, 0.136719, 0.121094, 0.226563, 0.160156, 0.238281,
      0.171875, 0.25,     0.203125, 0.248047, 0.123047, 0.259766, 0.134766,
      0.21875,  0.179688, 0.138672, 0.150391, 0.152344, 0.164063, 0.21875,
      0.175781, 0.226563, 0.183594, 0.199219, 0.175781, 0.191406, 0.167969,
      0.216797, 0.177734, 0.138672, 0.150391, 0.035156, 0.035156, 0.015625,
      0.033203, 0.046875, 0.199219, 0.167969, 0.179688, 0.148438, 0.238281,
      0.25,     0.21875,  0.230469, 0.222656, 0.195313, 0.226563, 0.1875,
      0.171875, 0.152344, 0.230469, 0.191406, 0.214844, 0.171875, 0.242188,
      0.199219, 0.15625,  0.222656, 0.222656, 0.199219, 0.242188, 0.207031,
      0.214844, 0.208984, 0.199219, 0.193359, 0.224609, 0.236328, 0.140625,
      0.109375, 0.140625, 0.125,    0.208984, 0.181641, 0.138672, 0.123047,
      0.224609, 0.158203, 0.234375, 0.1875,   0.246094, 0.115234, 0.210938,
      0.167969, 0.212891, 0.171875, 0.207031, 0.1875,   0.140625, 0.191406,
      0.244141, 0.246094, 0.175781, 0.210938, 0.226563, 0.21875,  0.207031,
      0.21875,  0.242188, 0.257813, 0.191406, 0.203125, 0.238281, 0.179688,
      0.1875,   0.183594, 0.212891, 0.152344, 0.253906, 0.279297, 0.1875,
      0.242188, 0.179688, 0.191406, 0.261719, 0.224609, 0.210938, 0.189453,
      0.09375,  0.191406, 0.1875,   0.15625,  0.136719, 0.171875, 0.136719,
      0.132813, 0.162109, 0.140625, 0.140625, 0.09375,  0.21875,  0.162109,
      0.113281, 0.183594, 0.208984, 0.140625, 0.179688, 0.132813, 0.15625,
      0.183594, 0.175781, 0.201172, 0.21875,  0.117188, 0.15625,  0.181641,
      0.1875,   0.1875,   0.160156, 0.160156, 0.222656, 0.160156, 0.132813,
      0.109375, 0.291016, 0.140625, 0.117188, 0.199219, 0.15625,  0.283203,
      0.212891, 0.210938, 0.175781, 0.208984, 0.15625,  0.226563, 0.171875,
      0.195313, 0.144531, 0.212891, 0.166016, 0.199219, 0.152344, 0.183594,
      0.152344, 0.121094, 0.181641, 0.166016, 0.177734, 0.138672, 0.183594,
      0.136719, 0.152344, 0.117188, 0.242188, 0.207031, 0.21875,  0.212891,
      0.21875,  0.177734, 0.234375, 0.167969, 0.234375, 0.1875,   0.234375,
      0.1875,   0.214844, 0.21875,  0.214844, 0.21875,  0.230469, 0.234375,
      0.273438, 0.210938, 0.171875, 0.148438, 0.167969, 0.1875,   0.15625,
      0.09375,  0.037109, 0.074219, 0.15625,  0.152344, 0.191406, 0.152344,
      0.191406, 0.195313, 0.226563, 0.175781, 0.101563, 0.101563, 0.140625,
      0.179688};
  std::vector<std::string> glyph{
      "\u00a4", "\u263a", "\u263b", "\u00a6", "\u2666", "\u2663", "\u2660",
      "\u2022", "\u00a8", "\u00a9", "\u00ae", "\u2642", "\u2640", "\u00af",
      "\u00b3", "\u263c", "\u00b4", "\u00b8", "\u2195", "\u203c", "\u00b6",
      "\u00a7", "\u00b9", "\u21a8", "\u2191", "\u2193", "\u2192", "\u2190",
      "\u221f", "\u2194", "\u00be", "\u00c0", "\u0020", "\u0021", "\u0022",
      "\u0023", "\u0024", "\u0025", "\u0026", "\u0027", "\u0028", "\u0029",
      "\u002a", "\u002b", "\u002c", "\u002d", "\u002e", "\u002f", "\u0030",
      "\u0031", "\u0032", "\u0033", "\u0034", "\u0035", "\u0036", "\u0037",
      "\u0038", "\u0039", "\u003a", "\u003b", "\u003c", "\u003d", "\u003e",
      "\u003f", "\u0040", "\u0041", "\u0042", "\u0043", "\u0044", "\u0045",
      "\u0046", "\u0047", "\u0048", "\u0049", "\u004a", "\u004b", "\u004c",
      "\u004d", "\u004e", "\u004f", "\u0050", "\u0051", "\u0052", "\u0053",
      "\u0054", "\u0055", "\u0056", "\u0057", "\u0058", "\u0059", "\u005a",
      "\u005b", "\u005c", "\u005d", "\u005e", "\u005f", "\u0060", "\u0061",
      "\u0062", "\u0063", "\u0064", "\u0065", "\u0066", "\u0067", "\u0068",
      "\u0069", "\u006a", "\u006b", "\u006c", "\u006d", "\u006e", "\u006f",
      "\u0070", "\u0071", "\u0072", "\u0073", "\u0074", "\u0075", "\u0076",
      "\u0077", "\u0078", "\u0079", "\u007a", "\u007b", "\u007c", "\u007d",
      "\u007e", "\u00c1", "\u00c7", "\u00fc", "\u00e9", "\u00e2", "\u00e4",
      "\u00e0", "\u00e5", "\u00e7", "\u00ea", "\u00eb", "\u00e8", "\u00ef",
      "\u00ee", "\u00ec", "\u00c4", "\u00c5", "\u00c9", "\u00e6", "\u00c6",
      "\u00f4", "\u00f6", "\u00f2", "\u00fb", "\u00f9", "\u00ff", "\u00d6",
      "\u00dc", "\u00a2", "\u00a3", "\u00a5", "\u20a7", "\u0192", "\u00e1",
      "\u00ed", "\u00f3", "\u00fa", "\u00f1", "\u00d1", "\u00aa", "\u00ba",
      "\u00bf", "\u2310", "\u00ac", "\u00bd", "\u00bc", "\u00a1", "\u00ab",
      "\u00bb", "\u2591", "\u2592", "\u00c2", "\u2502", "\u2524", "\u00c3",
      "\u00c8", "\u00ca", "\u00cb", "\u00cc", "\u00cd", "\u00ce", "\u00cf",
      "\u00d0", "\u00d2", "\u2510", "\u2514", "\u2534", "\u252c", "\u251c",
      "\u2500", "\u253c", "\u00d3", "\u00d4", "\u00d5", "\u00d7", "\u00d8",
      "\u00d9", "\u00da", "\u00db", "\u00dd", "\u00de", "\u00e3", "\u00f0",
      "\u00f5", "\u00f8", "\u00fd", "\u00fe", "\u011e", "\u011f", "\u0130",
      "\u2518", "\u250c", "\u2588", "\u0131", "\u0152", "\u0153", "\u015e",
      "\u015f", "\u00df", "\u0393", "\u03c0", "\u0160", "\u0161", "\u00b5",
      "\u0178", "\u03a6", "\u017d", "\u03a9", "\u017e", "\u221e", "\u02c6",
      "\u02dc", "\u2229", "\u2261", "\u00b1", "\u2265", "\u2264", "\u2320",
      "\u2321", "\u00f7", "\u2248", "\u00b0", "\u2219", "\u00b7", "\u221a",
      "\u207f", "\u00b2", "\u25a0", "\u2014", "\u2018", "\u2019", "\u201a",
      "\u201c", "\u201d", "\u201e", "\u2020", "\u2021", "\u2026", "\u2030",
      "\u2039", "\u203a", "\u20ac", "\u2122", "\u0102", "\u0103", "\u0104",
      "\u0105", "\u0106", "\u0107", "\u010c", "\u010d", "\u010e", "\u010f",
      "\u0111", "\u0118", "\u0119", "\u011a", "\u011b", "\u0139", "\u013a",
      "\u013d", "\u013e", "\u0141", "\u0142", "\u0143", "\u0144", "\u0147",
      "\u0148", "\u0150", "\u0151", "\u0154", "\u0155", "\u0158", "\u0159",
      "\u015a", "\u015b", "\u0162", "\u0163", "\u0164", "\u0165", "\u016e",
      "\u016f", "\u0170", "\u0171", "\u0179", "\u017a", "\u017b", "\u017c",
      "\u0218", "\u0219", "\u021a", "\u021b", "\u02c7", "\u02d8", "\u02d9",
      "\u02db", "\u02dd", "\u0108", "\u0109", "\u010a", "\u010b", "\u011c",
      "\u011d", "\u0120", "\u0121", "\u0124", "\u0125", "\u0126", "\u0127",
      "\u0134", "\u0135", "\u015c", "\u015d", "\u016c", "\u016d", "\u0174",
      "\u0175", "\u0176", "\u0177", "\u1e40", "\u1e41", "\u0100", "\u0101",
      "\u0112", "\u0113", "\u0116", "\u0117", "\u0122", "\u0123", "\u012a",
      "\u012b", "\u012e", "\u012f", "\u0136", "\u0137", "\u013b", "\u013c",
      "\u0145", "\u0146", "\u014c", "\u014d", "\u0156", "\u0157", "\u016a",
      "\u016b", "\u0172", "\u0173", "\u0400", "\u0402", "\u0403", "\u0404",
      "\u0409", "\u040a", "\u040b", "\u040c", "\u040d", "\u040e", "\u040f",
      "\u0411", "\u0414", "\u0416", "\u0417", "\u0418", "\u0419", "\u041b",
      "\u03a0", "\u0423", "\u0426", "\u0427", "\u0428", "\u0429", "\u042a",
      "\u042b", "\u042c", "\u042d", "\u042e", "\u042f", "\u0431", "\u0432",
      "\u0433", "\u0434", "\u0436", "\u0437", "\u0438", "\u0439", "\u043a",
      "\u043b", "\u043c", "\u043d", "\u043f", "\u0442", "\u0444", "\u0446",
      "\u0447", "\u0448", "\u0449", "\u044a", "\u044b", "\u044c", "\u044d",
      "\u044e", "\u044f", "\u0450", "\u0452", "\u0453", "\u0454", "\u0459",
      "\u045a", "\u045b", "\u045c", "\u045d", "\u045e", "\u045f", "\u0490",
      "\u0491", "\u2116", "\u0492", "\u0493", "\u0494", "\u0495", "\u0496",
      "\u0497", "\u0498", "\u0499", "\u049a", "\u049b", "\u049c", "\u049d",
      "\u04a0", "\u04a1", "\u04a2", "\u04a3", "\u04a4", "\u04a5", "\u04aa",
      "\u04ab", "\u04af", "\u04b2", "\u04b3", "\u04b6", "\u04b7", "\u04b8",
      "\u04b9", "\u04ba", "\u04bb", "\u04d2", "\u04d3", "\u04d6", "\u04d7",
      "\u04d8", "\u04d9", "\u04e2", "\u04e3", "\u04e6", "\u04e7", "\u04e8",
      "\u04e9", "\u04ee", "\u04ef", "\u04f0", "\u04f1", "\u04f2", "\u04f3",
      "\u04f8", "\u04f9", "\u20ae", "\u2260", "\u2208", "\u2205", "\u2016",
      "\u2017", "\u2032", "\u2033", "\u21b5", "\u21d0", "\u21d1", "\u21d2",
      "\u21d3", "\u21d4", "\u21d5", "\u2206", "\u2227", "\u2228", "\u222a",
      "\u2302",
  };
  //  for (int i = 0; i < 512; ++i) {
  //    if (i % 80 == 0) printf("\n");
  //    std::cout << glyph[i];
  //  }
  //  printf("\n");

  for (int i = 0; i < 512; ++i) {
    std::cout << i << " :: " << glyph[i] << " (" << darkness[i] << ")" << std::endl;
  }
  // while (true) {
  //   int r = rand();
  //   std::cout << glyph[r % 512];
  //   usleep(500 + r % 2000);
  //   if (r % 10 == 1)  //
  //     fflush(stdout);
  // }
  return 0;
}
