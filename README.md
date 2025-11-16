# GPA Calculator in C

A small but robust **Grade Point Average (GPA) Calculator** written in C. It computes a student's GPA based on multiple courses, each with a credit value and a grade (letter or numeric). The project is designed to be clean, modular, and easy to extend — suitable for academic use, teaching, and as a portfolio piece.

---

## Features

- Supports **multiple courses** per student.
- Accepts **letter grades** (A, A-, B+, ..., F).
- Accepts **numeric grades** (0–100) and maps them to GPA points using a configurable scale.
- Uses **credit-weighted GPA**: \(\text{GPA} = \frac{\sum (\text{credits} \times \text{grade points})}{\sum \text{credits}}\).
- Robust input handling with validation and clear error messages.
- Modular architecture:
  - `gpa_calculator` for GPA logic.
  - `grade_scale` for grade-to-points conversion.
  - `input_utils` for safe user input.
- Simple **unit-style tests** in C (no external testing framework).

---

## Project Structure

```text
GPA-Calculator-C/
├── src/
│   ├── main.c
│   ├── gpa_calculator.c
│   ├── gpa_calculator.h
│   ├── grade_scale.c
│   ├── grade_scale.h
│   ├── input_utils.c
│   └── input_utils.h
├── tests/
│   └── test_gpa_calculator.c
├── Makefile
├── README.md
├── LICENSE
└── .gitignore
```

---

## Build Instructions

### Prerequisites

- A C compiler (tested with `gcc`, but `clang` or others should work).
- A POSIX-like environment (Linux, macOS, WSL, or similar). It should also build on Windows with MinGW or similar toolchains.

### Build the main application

From the project root:

```bash
make
```

This will:

- Create a `build/` directory (if not present).
- Compile all sources under `src/`.
- Link them into an executable named `gpa_calculator` (or `gpa_calculator.exe` on Windows-like environments).

### Run the application

```bash
./gpa_calculator
```

On Windows (MinGW, etc.):

```bash
./gpa_calculator.exe
```

---

## Running Tests

To compile and run the small test suite:

```bash
make test
./build/test_gpa_calculator
```

If everything is correct, the test program should exit with code `0` and print a short success message.

---

## Usage Walkthrough

1. **Start the program**

   ```text
   ===============================
        GPA Calculator (C)
   ===============================
   ```

2. **Enter the number of courses** (between 1 and 50):

   ```text
   Enter number of courses (1-50): 4
   ```

3. **Enter course information** for each course:

   For each course you will be asked for:

   - Course name (e.g. `Algorithms`, `Math-1`)
   - Credit hours (e.g. `3`, `4`, `2.5`)
   - Grade, either:
     - Letter grade: `A`, `B+`, `C-`, `F`, ...
     - Numeric grade: between `0` and `100` (e.g. `92.5`)

   Example dialog for a course:

   ```text
   --- Course 1 ---
   Course name: Algorithms
   Credit hours (0.5–10.0): 3
   Grade (letter like A- or numeric 0–100): A-
   ```

4. **View the computed GPA**:

   After all courses are entered, the program prints a summary:

   ```text
   --------------------------------
   Total credits: 14.0
   Total grade points: 47.2
   GPA: 3.37
   --------------------------------
   ```

5. **Repeat for another student** (optional):

   The program will ask:

   ```text
   Do you want to calculate GPA for another student? (y/n): n
   ```

   Enter `y` to start over, or `n` to exit.

---

## Grade Scale

The default letter-grade scale (configurable in `grade_scale.c`):

| Letter | Points |
|--------|--------|
| A+ / A | 4.0    |
| A-     | 3.7    |
| B+     | 3.3    |
| B      | 3.0    |
| B-     | 2.7    |
| C+     | 2.3    |
| C      | 2.0    |
| C-     | 1.7    |
| D+     | 1.3    |
| D      | 1.0    |
| F      | 0.0    |

Numeric grades (0–100) are mapped to these points with a simple rule-based scale, also implemented in `grade_scale.c`. If you want to adapt the scale to a specific university, you can modify that file only; no other code changes are required.

---

## Implementation Details

- **Arrays & Loops**: Courses are stored in an array of `Course` structures, and loops are used to:
  - Collect input for each course.
  - Aggregate total credits and grade points.
- **Struct-based Design**: Each course is represented as:

  ```c
  typedef struct {
      char   name[64];
      double credits;
      double grade_points;
  } Course;
  ```

- **Error Handling**:
  - Input is validated for sensible ranges.
  - Grades are validated; invalid input triggers a friendly re-prompt.
- **Separation of Concerns**:
  - `main.c` contains user interaction and high-level flow.
  - `gpa_calculator.[ch]` focuses on GPA computation.
  - `grade_scale.[ch]` handles mapping from grade to point values.
  - `input_utils.[ch]` isolates all user input logic and validation.

---

## Extending the Project

Some ideas for future improvements:

- Support for **different grading schemes** (e.g., 5-point systems, pass/fail, etc.).
- Export results to a **CSV or JSON** file.
- Add **command-line arguments** (e.g., pass grades via a file instead of interactive input).
- Interactive menu to **edit/remove** entered courses before final calculation.

---

## License

This project is licensed under the **MIT License**. See the `LICENSE` file for details.

---

## Author

- **Mobin Yousefi**  
  GitHub: [github.com/mobinyousefi-cs](https://github.com/mobinyousefi-cs)

