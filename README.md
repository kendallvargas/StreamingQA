# 🎬 Streaming Platform Payment Calculator (C++) 

## 👋 Hi there! This is my C++ project, along with the testing procedure. 

### 🎯 **Project Overview**
The C++ code consists of a short system that calculates the total amount to be paid based on hours watched on a streaming platform.

The main menu consists of 3 options:
1️⃣ First, enter the data and information so that the system calculates the amount
2️⃣ The second, show on a receipt all the required data based on what was entered on menu 1.
3️⃣ The third, close the system.

The user is asked for these details:
- Client ID
- Full Name
- Invoice number
- Number of hours watched on the platform
- If it is exempt from taxes

### ⚙️ **Conditions to be met in the execution of the code**
❖ The menu repeats until a correct option is entered (invalid: incorrect letters or numbers).
❖ Customer ID must not allow letters or numbers other than 9.
❖ Invoice number must not allow letters or numbers other than 6.
❖ Total hours viewed must not allow letters or numbers less than 0 or greater than 720.
❖ The tax menu repeats until a correct letter is entered.
❖ The return to the main menu repeats until a correct letter is entered.
❖ Important: You cannot access option 2 without having gone through option 1.

### 💰 **Logic of calculation for the final price**
There are already 2 fixed payments each month, which are:
fixedFee: 10 USD
contentProtection: 5 USD

The streaming hour has a fixed price of 2 USD per hour. For the additional hourly charge, it works as follows:
The first 10 hours have no additional charges.
❖ After 10 to 40 hours consumed, an additional 10% is applied to the final price.
❖ From 51 to 100 hours, 20% is applied to the final price.
❖ And above 100 hours, 30% is applied to the final price.

For the tax price, it is 13% of the final total price of the payment. This is if the client is not exempt from taxes, if they are exempt, this additional price is not added.

### 🧪 **Test Plan**
For the correct delivery of this C++ project, I need to test all the code and validate it worked correctly based on the project requirements. 
📄 Test Plan Document: PDF PDF PDF

### 📚**Test Cases**
📄 Test Case Document: PDF PDF PDF

### 🔧 **Reference for setting up C++ on Windows with VS code:**
- Set up [C++](https://code.visualstudio.com/docs/languages/)

### 🚀 **Instructions for running the code locally:**
- Install a git client such as [git bash](https://git-scm.com/downloads).

**Clone the repository:** 📥
```bash
git clone https://github.com/kendallvargas/StreamingQA.git
```

**Go to project location** 📂
```bash
cd StreamingQA
```

**Build and Run** ▶️