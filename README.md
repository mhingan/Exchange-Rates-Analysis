# Exchange Rates Analysis

This program reads exchange rate information from a file, calculates the average rate for each currency, and writes the minimum values of the rates to a text file.

## Input Format

The exchange rate data is stored in a file with the following format:

N
data_1 EUR USD GBP
data_2 EUR USD GBP
...


Where:
- `N` is the number of days for which the exchange rates are available.
- `data_i` is the date in the format ZZ.LL.
- `EUR`, `USD`, and `GBP` are the exchange rates from RON to the respective currencies.

## Program Features

1. **Define Structure:**
   - A structure is defined to represent the exchange rate information.

2. **Allocate Dynamic Memory:**
   - Dynamic memory is allocated for an array of structures to store the exchange rate data.

3. **Calculate Average Rates:**
   - A function calculates and displays the average exchange rates for each currency.

4. **Write Minimum Rates to File:**
   - Another function writes the minimum values of the exchange rates for each currency to a text file.


