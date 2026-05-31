# Colorful Log File Analyser (C++)

A high-performance command-line tool written in C++ to parse, filter, and analyze server log files. It categorizes logs into Errors, Warnings, Failed attempts, Critical errors, and Unauthorized actions.

## 🚀 Features
- **High Performance:** Uses `std::vector` to parse the file in a single pass (Single-Loop Optimization).
- **Hacker Vibes:** Features colorful live terminal output using ANSI escape codes.
- **Clean Reports:** Generates a beautifully structured `report.txt` ignoring empty error categories.

#How to compile🛠️

g++ log-file-analyzer.cpp -o log-file-analyzer

#How to run💨

./log-file-analyzer     (linux)
log-file-analyzer.exe   (Windows)
