# codealpha_task4c-
# Features
Core Class Design: Creates distinct structures for Customer, Account, and Transaction to keep data organized.
Management Functions: Includes tools to build new customer profiles and link them to unique bank accounts.
Financial Operations: Allows users to perform essential actions like deposits, withdrawals, and fund transfers between accounts.
History Tracking: Automatically saves every action into a transaction log so users can view their recent activity.
Account Summary: Displays a clear view of the current balance and personal details to the customer.

# Logic & Structure
Object-Oriented Setup: Uses classes to group related data, such as putting a balance and account number inside the Account class.
Transaction Logging: Every time money moves, a new Transaction object is created and stored in a list or vector for record-keeping.
Balance Validation: Before a withdrawal or transfer, the system checks if the account has enough money to prevent a negative balance.
Data Linking: Connects Customer objects to their respective Account objects using unique IDs.
