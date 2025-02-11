# Online Book Reader

## **Overview**
This project is a **console-based online book reader system** implemented in C++. It allows users to:
- **Admins**: Add and manage books.
- **Customers**: Read books, navigate through pages, and track reading sessions.

The system is designed using **object-oriented principles** and incorporates **design patterns** such as **Singleton** and **Iterator**.

---

## **Features**
1. **Book Management**:
   - Admins can add books with a title, author, and pages.
   - Books are stored in a centralized system.

2. **User Management**:
   - Two types of users: **Admins** and **Customers**.
   - Admins can log in and manage books.
   - Customers can sign up, log in, and read books.

3. **Reading Sessions**:
   - Customers can start new reading sessions or continue old ones.
   - Sessions track the current page being read.

4. **Navigation**:
   - Customers can navigate through book pages (next, previous, jump to a specific page).

5. **Persistence**:
   - Books and users are loaded into memory at startup (hardcoded for now).

---

## **How It Works**
1. **Admins**:
   - Log in using credentials.
   - Add new books to the system.

2. **Customers**:
   - Sign up or log in.
   - View available books.
   - Start a new reading session or continue an old one.
   - Navigate through book pages.

---

## **Class Structure**
### **1. `Book` Class**
- Represents a book with a title, author, and pages.
- Methods: `getPage()`, `getName()`, `getNumOfPages()`, `setBook()`.

### **2. `BookPrinter` Class**
- Implements the **Iterator Design Pattern** to navigate through book pages.
- Methods: `printNext()`, `printPrevious()`, `printCurrent()`, `setPage()`.

### **3. `Session` Class**
- Represents a reading session for a specific book.
- Tracks the current page being read.

### **4. `Customer` Class**
- Represents a customer who reads books.
- Manages reading sessions.

### **5. `Admin` Class**
- Represents an admin who manages books.
- Can add new books to the system.

### **6. `SystemBooks` Class**
- Manages the collection of books using the **Singleton Design Pattern**.
- Methods: `insertBook()`, `viewBooks()`, `loadBooks()`.

### **7. `SystemUsers` Class**
- Manages the collection of users (admins and customers) using the **Singleton Design Pattern**.
- Methods: `signUp()`, `customerLogIn()`, `adminLogIn()`, `loadAdmins()`.

### **8. `RunSystem` Class**
- Manages the overall flow of the program.
- Displays menus for admins and customers.

### **9. `StartSessions` Class**
- Manages reading sessions for customers.
- Methods: `startNewSession()`, `ContinueOldSession()`, `openBook()`.

---

## **Design Patterns**
1. **Singleton**:
   - Used in `SystemBooks` and `SystemUsers` to ensure only one instance of these classes exists.

2. **Iterator**:
   - Implemented in `BookPrinter` to navigate through book pages.

3. **Inheritance**:
   - `Customer` and `Admin` inherit from `User` to reuse common attributes and methods.

---

## **How to Run**
1. Clone the repository:
   ```bash
   git clone https://github.com/mode4a/online-Book-reader.git
1. Navigate to the project directory:
    ```bash
    cd online-Book-reader
    ```
1. compile the code:
    ```bash
    g++ *.cpp -o book_reader
    ```
1. run the executable:
    ```bash
    ./book_reader
    ```
