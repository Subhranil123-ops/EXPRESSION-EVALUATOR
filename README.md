# 🚀 Coding Analyzer & Expression Evaluator

![Node.js](https://img.shields.io/badge/Node.js-339933?logo=node.js&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?logo=cplusplus&logoColor=white)
![Express](https://img.shields.io/badge/Express.js-000000?logo=express&logoColor=white)
![Crow](https://img.shields.io/badge/Crow-C++%20Web%20Framework-0A66C2)
![Bootstrap](https://img.shields.io/badge/Bootstrap-7952B3?logo=bootstrap&logoColor=white)
![Project](https://img.shields.io/badge/Project-FullStack-blue)
![DSA](https://img.shields.io/badge/DataStructure-Stack-orange)
![Status](https://img.shields.io/badge/status-active-success)

A full-stack web application that analyzes code complexity and evaluates mathematical expressions using core data structures.

---

## 📌 Overview

This project demonstrates the real-world application of **Data Structures (Stack)** by building:

* 🔢 Expression Evaluator (Infix, Prefix, Postfix)
* 📊 Code Complexity Analyzer (loop depth & estimation)

The system is built using a **C++ backend (Crow)** and a **Node.js server**, with a responsive web interface.

---

## 🧠 Core Concepts Used

* Stack (Expression Evaluation)
* Parsing & Conversion Algorithms
* Time Complexity Estimation
* REST API Design

---

## ⚙️ Tech Stack

### 🔹 Backend (Core Logic)

* C++
* Crow Framework
* Custom logic for parsing & evaluation

### 🔹 Server Layer

* Node.js
* Express.js
* Axios

### 🔹 Frontend

* EJS
* Bootstrap 5
* Font Awesome

---

## 🏗️ Architecture

```
Browser (UI)
     ↓
Node.js (Express Server)
     ↓
C++ API (Crow)
     ↓
Data Structure Logic (Stack / Analysis)
```

---

## ✨ Features

### 🔹 Expression Evaluator

* Supports:

  * Infix
  * Prefix
  * Postfix
* Converts between formats
* Evaluates final result

### 🔹 Code Analyzer

* Counts:

  * for loops
  * if / else
  * while loops
* Calculates:

  * Maximum nesting depth
  * Estimated time complexity

### 🔹 Error Handling

* Structured JSON responses
* Handles:

  * Invalid expressions
  * Empty input
  * Division by zero
  * Invalid code input

---

## 📦 API Endpoints

### 🔹 POST `/expression`

#### Request:

```json
{
  "expression": "5 6 2 * + 3 -"
}
```

#### Response:

```json
{
  "result": 14,
  "prefix": "- + 5 * 6 2 3",
  "infix": "((5 + (6 * 2)) - 3)",
  "postfix": "5 6 2 * + 3 -"
}
```

---

### 🔹 POST `/analyze`

#### Request:

```json
{
  "code": "for(int i=0;i<n;i++){...}"
}
```

#### Response:

```json
{
  "for": 1,
  "if": 0,
  "while": 0,
  "maxDepth": 1,
  "estimatedComplexity": "O(n)"
}
```

---

## 🧪 Testing

The API has been tested using:

* Curl
* Browser integration

Test cases include:

* Valid expressions
* Invalid inputs
* Edge cases (empty input, divide by zero)
* Nested loops for complexity

---

## 🚀 Getting Started

### 🔹 1. Clone the repository

```bash
git clone https://github.com/your-username/your-repo.git
cd your-repo
```

---

### 🔹 2. Setup Node.js

```bash
npm install
```

---

### 🔹 3. Setup environment variables

Create a `.env` file:

```env
API_URL=http://localhost:5000
```

---

### 🔹 4. Run C++ Server

```bash
g++ main.cpp -o app -lpthread
./app
```

---

### 🔹 5. Run Node Server

```bash
node index.js
```

---

### 🔹 6. Open in browser

```
http://localhost:3000
```

---

## 📸 Screenshots

(Add screenshots here)

---

## 📈 Future Improvements

* Live evaluation (no page reload)
* Expression history
* Step-by-step stack visualization
* Support for variables

---

## 👨‍💻 Author

**Subhranil Mandal**

---

## 📄 License

This project is for educational purposes.
