#include <iostream>
#include <vector>
#include <chrono> 

// DYNAMIC PROGRAMMING

//------------------------------------------------------------------------------------
constexpr size_t fibonacci_id = 43;


// DP TOP-DOWN approach
std::vector<size_t> memo(fibonacci_id + 1, -1);
size_t fibonacci_TOPDOWN(size_t n, std::vector<size_t>& memo)
{
   if (n <= 1) return n;

   if (memo[n] != -1) return memo[n];

   return memo[n] = fibonacci_TOPDOWN(n - 1, memo) + fibonacci_TOPDOWN(n - 2, memo);
}

//------------------------------------------------------------------------------------


// DP BOTTOM-UP approach
size_t fibonacci_BOTTOMUP(size_t n)
{
   if (n <= 1) return n;
   std::vector<size_t> DP(n + 1, -1);
   DP[0] = 0;
   DP[1] = 1;

   for (int i = 2; i <= n; ++i)
   {
      DP[i] = DP[i - 1] + DP[i - 2];
   }

   return DP[n];

}

//--------------------------------------------------------------------


// approach without DP 
size_t fibonacci(size_t n)
{
   if (n <= 1) return n;

   return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
   // DP TOP-DOWN
   auto DP_TD_TIME_START = std::chrono::high_resolution_clock::now();
   auto result_TD_DP = fibonacci_TOPDOWN(fibonacci_id, memo);
   auto DP_TD_TIME_END = std::chrono::high_resolution_clock::now();
   
   std::chrono::duration<double, std::milli> DP_TD_DURATION = DP_TD_TIME_END - DP_TD_TIME_START;

   std::cout << "DP (TOP-DOWN APPROACH)\n";
   std::cout << "Result: : fibonacci " << fibonacci_id << " = " << result_TD_DP << "," 
                               << " Execution time: " 
                               << DP_TD_DURATION.count() << " milisecond\n\n";


   //----------------------------------------------------------------------

   // DP BOTOM-UP 
   auto DP_BU_TIME_START = std::chrono::high_resolution_clock::now();
   auto result_BU_DP = fibonacci_BOTTOMUP(fibonacci_id);
   auto DP_BU_TIME_END = std::chrono::high_resolution_clock::now();
   
   std::chrono::duration<double, std::milli> DP_BU_DURATION = DP_BU_TIME_END - DP_BU_TIME_START;

   std::cout << "DP (BOTTOM-UP APPROACH)\n";
   std::cout << "Result: : fibonacci " << fibonacci_id << " = " << result_BU_DP << "," 
                               << " Execution time: " 
                               << DP_BU_DURATION.count() << " milisecond\n\n";


   //----------------------------------------------------------------------

   // Without DP
   auto NO_DP_TIME_START = std::chrono::high_resolution_clock::now();
   auto result_NO_DP = fibonacci(fibonacci_id);
   auto NO_DP_TIME_END = std::chrono::high_resolution_clock::now();
   
   std::chrono::duration<double, std::milli> NO_DP_DURATION = NO_DP_TIME_END - NO_DP_TIME_START;
   
   std::cout << "without DP \n";
   std::cout << "Result: : fibonacci " << fibonacci_id << " = " << result_NO_DP << "," 
                               << " Execution time: " 
                               << NO_DP_DURATION.count() << " milisecond\n\n";
}