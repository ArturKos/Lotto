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
- **Manual draw entry** -- a dedicated form (`TOknoDodajWynik`) with 6 spin-edit controls lets the user record real lottery results; values default to the 6 most frequent numbers
- **Detailed statistics view** -- a statistics form (`TOknoSzczegolyStatystyk`) shows three value lists: raw counts per number, sorted counts, and average draw intervals, plus a full history list of all recorded draws
- **Random number drawing** -- a drawing form (`TOknoGenerator`) generates 6 distinct numbers (1--49) using a Fisher-Yates shuffle; a timer-based auto-roll mode continuously re-draws for an animated "slot machine" effect
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
  Lotek.bpr                         # C++ Builder project file
  Lotek.cpp                         # WinMain entry point
  Lotek.res                         # Compiled resource file
  Statystyka.h                      # Domain layer (VCL-free) -- class declaration
  Statystyka.cpp                    # Domain layer -- file I/O (std::fstream), counters, ranking
  OknoGlowne.{cpp,h,dfm}            # Main form -- bar chart, ranking label, status bar
  OknoDodajWynik.{cpp,h,dfm}        # Draw entry form -- 6 spin edits, save to statistics file
  OknoSzczegolyStatystyk.{cpp,h,dfm}# Statistics form -- value lists, full draw history
  OknoGenerator.{cpp,h,dfm}         # Random drawing form -- manual and auto-roll modes
  Statystyka.lot                    # Binary statistics data file (6 bytes per draw)
```

## Data Format

`Statystyka.lot` stores lottery draws as sequential 6-byte records. Each byte holds one drawn number (1--49). The `KolektorStatystyk` class reads the file on construction, populates 49 occurrence counters, stores the full history as a `std::vector<Losowanie>`, and precomputes a frequency-sorted ranking (`WpisRankingu[49]`) that is rebuilt only when data changes.

## Architecture Notes

The domain layer (`Statystyka.h`/`Statystyka.cpp`) is independent of VCL and can in principle be unit-tested in isolation. The four form classes (`TOknoGlowne`, `TOknoDodajWynik`, `TOknoSzczegolyStatystyk`, `TOknoGenerator`) hold no domain logic -- they read from a single shared `KolektorStatystyk` instance owned by the main window and delegate all persistence and statistics to it.

Source files are saved in CP1250 (Windows Polish) because the UI strings contain Polish diacritics; the `Lotek.bpr` project declares `CodePage=1250` accordingly.

## Screenshot

![image](https://user-images.githubusercontent.com/17749811/152384609-6bc45a90-2ccd-46b9-8eb0-a9a108ff474c.png)
