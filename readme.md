# Math Functions & Raylib Implementation Report

This report documents the C++ implementations of five mathematical functions (`l`, `s`, `f`, `g`, and `h`) rendered in a basic [Raylib](https://raylib.com) window. It outlines the thought process behind translating mathematical formulas into code and explores how these concepts apply to game development.

---

## 1. Function Breakdown & Thought Process

### Function `l(x, y)` — Euclidean Distance / Vector Magnitude
* **Implementation:** Uses `std::sqrt(x * x + y * y)` to compute the length of a 2D vector $(x, y)$.
* **Thought Process:**  i guessed raylib or cmath had somthing for square root.
* **Test Input & Output:** `l(3.0f, 4.0f)` evaluates to `5.00` (a classic 3-4-5 right triangle).

### Function `s(x)` — Absolute Value
* **Implementation:** Uses `std::abs(x)` to return the non-negative magnitude of a floating-point number.
* **Thought Process:** i googled and found abs that makes negatives in to positives.
* **Test Input & Output:** `s(-5.0f)` evaluates to `5.00`.

### Function `f(n)` — Summation Series ($\sum$)
* **Implementation:** Loops from `i = 1` to `n`, accumulating $\frac{i^2}{n}$ into a `float` sum.
* **Thought Process:** 
  * **Edge Case Handling:** Included an early `if (n == 0)` check to prevent division by zero.
  * **Type Casting:** Used `static_cast<float>(i * i)` before dividing by `n`. Without casting, integer division in C++ would truncate the decimal values and produce inaccurate results.
* **Test Input & Output:** `f(5)` evaluates to `11.00`.

### Function `g(n)` — Nested Summation ($\sum$) and Product ($\prod$)
* **Implementation:** Uses an outer `for` loop for the summation and an inner `for` loop to calculate a conditional product where `j != i`.
* **Thought Process:** 
  * **Precision:** Used `double` instead of `float` because nested products grow very quickly and can easily overflow or lose precision.
  * **Neutral Element:** Initialized `prod = 1.0` (rather than `0.0`) so multiplication accumulates properly, and added `if (j != i)` to skip the excluded index defined in the formula.
* **Test Input & Output:** `g(3)` evaluates to `90.00`.

### Function `h(theta, x, y)` — Trigonometric & Algebraic Expression
* **Implementation:** Breaks a complex multi-term formula involving $\cos(\theta)$, $\sin(\theta)$, and a square root into three readable sub-variables (`term1`, `term2`, `term3`) before summing them.
* **Thought Process:** Splitting a long equation into smaller intermediate variables makes the code much easier to debug, read, and verify against the original mathematical notation.
* **Test Input & Output:** `h(0.5f, 2.0f, 3.0f)` evaluates to `-4.52`.

---

## 2. Raylib Integration & Rendering

* **Setup:** Initialized an `800x600` window at 60 FPS with `FLAG_MSAA_4X_HINT` enabled for smoother text and edge rendering.
* **Display:** Inside the main game loop (`while (!WindowShouldClose())`), `TextFormat("Result: %.2f", ...)` is used to format floating-point values to two decimal places and draw them cleanly onto the screen.
* **Optimization Note:** In a larger game project, static math calculations like these would be computed once *outside* the `while` loop rather than every frame to save CPU cycles.

---

## 3. Applications in Game Development

The mathematical concepts practiced in these functions form the backbone of game programming:

1. **Vector Magnitude (`l`):**
   * **Hitboxes & Collision Detection:** Checking if the distance between two circular objects (e.g., a bullet and an enemy) is less than the sum of their radii.
   * **Aggro Ranges & Audio Falloff:** Triggering an enemy AI to chase the player when the distance drops below a threshold, or lowering sound effect volume based on distance from the camera.
2. **Absolute Value (`s`):**
   * **Input Deadzones:** Checking if `std::abs(joystickAxis) > 0.1f` to ignore minor controller drift.
   * **Symmetrical Logic:** Measuring horizontal or vertical distance between a player and a platform regardless of which side the player is on.
3. **Summations & Series (`f` and `g`):**
   * **XP & Leveling Curves:** Calculating total experience points required to reach level $n$ using progressive scaling formulas.
   * **Damage & Loot Scaling:** Computing cumulative stats, area-of-effect falloff, or procedural wave difficulty across multiple rounds.
4. **Trigonometry (`h`):**
   * **2D Rotation & Aiming:** Using `std::cos(theta)` and `std::sin(theta)` to rotate sprites, calculate bullet trajectories from a turret's angle, or orbit objects around a central point.
   * **Smooth Oscillations:** Creating floating animations for collectibles, camera shake, or swaying foliage using sine and cosine waves over time.
