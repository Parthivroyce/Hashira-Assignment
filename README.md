# Hashira-Assignment
In this assignment, i have worked on a simplified version of Shamir's Secret Sharing algorithm.


# 🔐 Secret Reconstruction using Lagrange Interpolation

This project implements a simple simulation of Shamir's Secret Sharing scheme. It reconstructs the hidden secret (f(0)) from a set of known points using **Lagrange Interpolation** over integers.

## 🧠 Problem Intuition

Given `k` points from a polynomial `f(x)`, use Lagrange interpolation to find the constant term `f(0)` (the secret).

---

## 🚀 How It Works

1. **Base Conversion:** Input strings are given in various bases (binary, octal, decimal, hex, etc.). They are first converted to decimal.
2. **Interpolation:** We pick the first `k` points and apply Lagrange interpolation at `x = 0` to compute the secret.
3. **Output:** The reconstructed secret for each test case is printed.

---

## 🧪 Test Cases

Two test cases are hardcoded directly in the C++ program:

- **Test Case 1**: 4 points, `k = 3`
- **Test Case 2**: 10 points, `k = 7`

Both are sorted and then interpolated to find the secrets.

---

## ✅ Output (Screenshot Attached)

Secret for Testcase 1 (f(0)) = 3
Secret for Testcase 2 (f(0)) = 79836264049851

yaml
Copy
Edit

---

## 🛠 Tech Stack

- Language: C++
- Compiler: Any standard C++ compiler (tested on [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler))

---

## 📁 Files

- `main.cpp` – Main solution file (contains logic for base conversion and interpolation)
- `README.md` – You are here 😊
- `screenshot.png` – Output proof of correctness (attached separately)

---

## 💡 Notes

- No external libraries used except standard headers.
- Clean, beginner-friendly integer-only implementation.
- Ready to run in any online/offline C++ environment.

---

## 🙌 Acknowledgment

This code demonstrates fundamental understanding of:
- Number systems and base conversion
- Polynomial interpolation
- Secret sharing (conceptual)

---
