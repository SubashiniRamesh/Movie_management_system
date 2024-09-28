---

# Movie Booking Management System

This is a simple C program that allows users to book movie tickets, capture customer details, and calculate the total booking fee based on the selected ticket type and the number of guests. The booking records are stored in a file (`data.txt`).

## Features
- Book movie tickets for multiple guests.
- Select from three different ticket types: Premium, First Class, and Second Class.
- Automatically calculate the total booking fee based on the number of guests and the selected ticket type.
- Store booking records in a file for future reference.

## Usage
1. **Enter Booking Details**:  
   The program will prompt you to enter movie booking information such as:
   - Movie booking number (4-digit code)
   - Customer name
   - Movie name
   - Movie schedule (in `DD-MM-YYYY` format)
   - Movie time (24-hour format)
   - Number of guests
   - House number
   - Ticket type (Premium, First Class, Second Class)

2. **Ticket Pricing**:  
   The program offers three different ticket types:
   - **Premium**: ₹200 per guest
   - **First Class**: ₹150 per guest
   - **Second Class**: ₹100 per guest

3. **Calculate Total Fee**:  
   Based on the number of guests and the selected ticket type, the program will calculate the total booking fee.

4. **Record Storage**:  
   Once the details are entered, the booking record is stored in the `data.txt` file in the following format:
   ```
   BookingNumber,CustomerName,MovieName,Schedule,Time,Guests,HouseNumber,TicketType,TotalFee
   ```

## Example
Here is an example interaction with the program:
```
Enter Movie Booking Number (XXXX): 1234
Enter Name of Customer: John Doe
Enter Name of Movie: Avengers
Enter Movie Schedule (DD-MM-YYYY): 15-10-2024
Enter Time (XXXX): 1800
Enter Number of Guests: 3
Enter House Number: 7
Select Ticket Type: 
1. Premium (200 per guest)
2. First Class (150 per guest)
3. Second Class (100 per guest)
Enter your choice (1-3): 1
Total Fee for 3 guests: 600
Record insert successful!
```

![image](https://github.com/user-attachments/assets/1abcb342-cf6d-42a7-ad58-026e3a73a510)


## File Format
Each booking record is stored in the `data.txt` file as:
```
1234,John Doe,Avengers,15-10-2024,1800,3,7,Premium,600
```


## Future Enhancements
- Implement functionality to view or modify existing bookings with better UI interaction.
- Add support for cancellation of bookings.
- Enhance input validation for dates and times.
  

