# 🍽️ KOB Food Delivery App

Welcome to the GitHub repository of **KOB Food Delivery App**, a command-line food ordering system built using the C programming language. This project was created during the **Fall 2024 semester** for my **Programming Fundamentals** course at FAST University.



## 📌 Description

KOB Food Delivery App simulates a basic yet complete food delivery experience within a terminal interface. Users can register, log in, browse available restaurants, order food, and receive confirmation — all from a command-line environment.



## 🚀 Features

* **User Registration & Login**

  * Secure user authentication with limited login attempts
  * Separate login paths for regular users and home chefs

* **Email Notifications**

  * Real-time alerts on signup, login, and successful order placement (via external script integration)

* **Location Handling**

  * Delivery cities list
  * Input validation for city and address

* **Smart Restaurant Listing**

  * Dynamically shows restaurants available based on the current day

* **Menu Display & Ordering**

  * Interactive cart building
  * Item selection, quantity setting, and order summary

* **Billing System**

  * Auto-calculated VAT
  * Delivery charges based on city
  * Coupon code support for discounts

* **Order Confirmation**

  * Summary printed on-screen
  * Confirmation sent via email



## 📁 Folder Structure

```
KOB-Food-Delivery/
│
├── main.c                   # Main source code
├── data/
│   ├── users.txt            # Registered users data
│   ├── restaurants.txt      # Restaurant lists by day
│   ├── menus/               # Menus for each restaurant
│   └── orders/              # Order history logs
├── email_script.py         # Script to send email notifications
└── README.md               # Project documentation (this file)
```



## 🧠 What I Learned

* Core logic building in C
* File handling (reading/writing structured data)
* Modular programming
* User input validation techniques
* Simulating real-world app behavior through the command line
* Using Python for sending automated emails



## 🛠️ Tech Stack

* **Language:** C
* **Tools:** GCC, VS Code
* **Others:** Python for email integration






## ✅ How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/KOB-Food-Delivery.git
   ```
2. Compile the C program:

   ```bash
   gcc main.c -o kob_app
   ```
3. Run the program:

   ```bash
   ./kob_app
   ```
4. Make sure Python is installed if you want to use email notifications.



## 📜 License

This project is licensed under the **MIT License**. Feel free to use, modify, and share!



## 💬 Feedback

If you try out the app or go through the code, I’d love to hear your thoughts. Feel free to create issues or submit pull requests. ⭐



Made with ❤️ by Muhammad Omer Siddiqui
