# 🎬 Streaming Platform Payment Calculator (C++) 

## 👋 Hi there! This is my C++ project, along with the testing procedure. 

### 🎯 **Project Overview**
The C++ code consists of a short system that calculates the total amount to be paid based on hours watched on a streaming platform.

The main menu consists of 3 options: <br/>
1️⃣ First, enter the data and information so that the system calculates the amount.<br/>
2️⃣ The second, show on a receipt all the required data based on what was entered on menu 1.<br/>
3️⃣ The third, close the system.<br/>

The user is asked for these details:<br/>
- Client ID<br/>
- Full Name<br/>
- Invoice number<br/>
- Number of hours watched on the platform<br/>
- If it is exempt from taxes

### ⚙️ **Conditions to be met in the execution of the code**
❖ The menu repeats until a correct option is entered (invalid: incorrect letters or numbers).<br/>
❖ Client ID must not allow letters or numbers other than 9.<br/>
❖ Invoice number must not allow letters or numbers other than 6.<br/>
❖ Total hours viewed must not allow letters or numbers less than 0 or greater than 720.<br/>
❖ The tax menu repeats until a correct letter is entered.<br/>
❖ The return to the main menu repeats until a correct letter is entered.<br/>
❖ Important: You cannot access option 2 without having gone through option 1.

### 💰 **Logic of calculation for the final price**
There are already 2 fixed payments each month, which are:<br/>
- fixedFee: 10 USD<br/>
- contentProtection: 5 USD

The streaming hour has a fixed price of 2 USD per hour. For the additional hourly charge, it works as follows:<br/>
The first 10 hours have no additional charges.<br/>
❖ Category 1: The first 10 hours have no additional charges.<br/>
❖ Category 2: After 10 to 50 hours consumed, an additional 10% is applied to the final price + the price of the first 10 hours consumed.<br/>
❖ Category 3: From 51 to 100 hours, the price of the first 10 hours consumed + 10% of the previous 40 hours, and 20% is applied to the final price based on the hours consumed in this category.<br/>
❖ Category 4: Above 100 hours, the price of the first 10 hours consumed(first category) + 10% of the previous 40 hours (second category) + 20% of the third category + 30% applied to the hours above 100 hours. <br/>

The tax price is 13% of the final total payment price. If the client is exempt from taxes, this additional price is not added.<br/>

### 🧪 **Test Plan**
For the correct delivery of this C++ project, I need to test all the code and validate it works correctly based on the project requirements. <br/><br/>
📄 Test Plan Document: [Test_Plan](https://github.com/kendallvargas/StreamingQA/blob/master/QA%20Section/Test_Plan.pdf)

### 📚**Test Cases**
📄 Test Case Document: [Test_Case](https://github.com/kendallvargas/StreamingQA/blob/master/QA%20Section/Test_Cases_Streaming.pdf) <br/> <br/>
The reporting of the bugs is documented using Notion, here is the link to view the reports: [backlog](https://kendallvargas.notion.site/Streaming-Project-Bug-Report-List-129a2534d25a80d5bee2f764a4ffb6b2)<br/>
Another way to access the links of the bugs directly from the Test Cases is to download the PDF of the TC from the folder >>> [here](https://github.com/kendallvargas/StreamingQA/blob/master/QA%20Section/Test_Cases_Streaming.pdf).

### 🔧 **Reference for setting up C++ on Windows with VS code:**
- Set up [C++](https://code.visualstudio.com/docs/languages/cpp)

### 🚀 **Instructions for running the code locally:**
- Install a git client such as [git bash](https://git-scm.com/downloads).

**Clone the repository:** 📥
```bash
git clone https://github.com/kendallvargas/StreamingQA.git
```

- Go to the project location and open the 'main' file 📂

- Build and Run ▶️

### 📹 **Example of a normal end-to-end flow in the system:**

https://github.com/user-attachments/assets/7cbee255-267f-4713-8f87-8531d1784a96

