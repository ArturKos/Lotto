# Lotto

![C++ Builder](https://img.shields.io/badge/C%2B%2B%20Builder-6.0-00599C?style=flat&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/platform-Windows-0078D6?style=flat&logo=windows&logoColor=white)
![VCL](https://img.shields.io/badge/framework-Borland%20VCL-blueviolet?style=flat)
![License](https://img.shields.io/badge/license-MIT-blue?style=flat)

Lottery number analyzer for a 6-of-49 game. Tracks historical draws in a binary statistics file, visualizes number frequencies with a color-coded bar chart, and includes a random number drawing feature with optional auto-roll animation.

## Features

- **Frequency bar chart** -- renders a 49-bar chart on a `TPaintBox` canvas, one bar per number, with 7 alternating colors; bar height represents occurrence count with automatic baseline normalization
- **Interactive hover tooltips** -- moving the mouse over a bar displays that number's total occurrences, average draw interval, and total draw count in the status bar
- **Sorted frequency ranking** -- numbers are sorted by frequency (descending) and displayed in a label, showing the most and least common picks at a glance
- **Manual draw entry** -- a dedicated form (`TForm2`) with 6 spin-edit controls lets the user record real lottery results; values default to the 6 most frequent numbers
- **Detailed statistics view** -- a statistics form (`TForm3`) shows three value lists: raw counts per number, sorted counts, and average draw intervals, plus a full history list of all recorded draws
- **Random number drawing** -- a drawing form (`TForm4`) generates 6 random numbers (1--49) on demand; a timer-based auto-roll mode continuously re-draws for an animated "slot machine" effect
- **Binary file persistence** -- all draw history is stored in `Statystyka.lot` as packed 6-byte records, enabling compact storage and fast sequential reads
- **Non-resizable windows** -- all forms intercept `FormCanResize` to maintain fixed layouts

## Dependencies

| Dependency | Purpose |
|---|---|
| C++ Builder 6.0 | IDE and compiler |
| Borland VCL | GUI framework |
| `CSPIN` component | Spin-edit controls for number entry |

## Build Instructions

1. Open `Lotek.bpr` in Borland C++ Builder 6.0.
2. Ensure the `CSPIN` third-party component is installed in the IDE.
3. Build the project (Ctrl+F9) or run directly (F9).

## Project Structure

```
Lotto/
  Lotek.bpr           # C++ Builder project file
  Lotek.cpp           # WinMain entry point
  Lotek.res           # Compiled resource file
  MAIN.CPP            # Main form -- bar chart rendering, frequency sorting, status bar
  MAIN.h              # Main form header -- stat class, liczba struct, TForm1
  MAIN.dfm            # Main form layout (paint box, menu, toolbar, labels)
  Unit2.cpp           # Draw entry form -- 6 spin edits, save to statistics file
  Unit2.h             # Draw entry form header
  Unit2.dfm           # Draw entry form layout
  Unit3.cpp           # Statistics form -- value lists, full draw history
  Unit3.h             # Statistics form header
  Unit3.dfm           # Statistics form layout
  Unit4.cpp           # Random drawing form -- manual and auto-roll modes
  Unit4.h             # Random drawing form header
  Unit4.dfm           # Random drawing form layout
  Statystyka.lot      # Binary statistics data file (6 bytes per draw)
```

## Data Format

`Statystyka.lot` stores lottery draws as sequential 6-byte records. Each byte holds one drawn number (1--49). The `stat` class reads this file on startup, tallying occurrence counts for all 49 numbers and tracking the total number of draws.

## Screenshot

![image](https://user-images.githubusercontent.com/17749811/152384609-6bc45a90-2ccd-46b9-8eb0-a9a108ff474c.png)
