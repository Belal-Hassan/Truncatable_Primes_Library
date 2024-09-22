<a name="readme-top"></a>
<hr>
<br />
<div align="center">
  <a href="https://github.com/Belal-Hassan/Truncatable_Primes_Library">
  </a>
<h3 align="center">Truncatable Primes</h3>
  <p align="center">
    <br />
    <a href="https://github.com/Belal-Hassan/Truncatable_Primes_Library"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Belal-Hassan/Truncatable_Primes_Library">View Demo</a>
    ·
    <a href="https://github.com/Belal-Hassan/Truncatable_Primes_Library/issues">Report Bug</a>
    ·
    <a href="https://github.com/Belal-Hassan/Truncatable_Primes_Library/issues">Request Feature</a>
  </p>
</div>
<hr>


<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about">About The Project</a>
    </li>
    <li>
      <a href="#functions">Functions & Definitions</a>
    </li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

## About The Project
<section id="about"> </section>

This library proviedes the user with Functions & Definitions for finding 3 types of truncatable primes: 

1. Left-truncatable primes.
2. right-truncatable priems.
3. two-sided primes (1 & 2 at the same time).

The code starts with a vector containing the initial primes `(2, 3, 5, 7)` for right truncatable primes. It then iteratively extends the primes by appending digits `(1, 3, 7, 9)` to its right end. For left truncatable primes, the vector starts with `(3, 7)` only (`5` and `2` will always make the number divisible), and then appends the numbers from `1` till `9` to the left. After each extension, the primality of the new numbers is checked. This process continues until the desired length is reached.

This approach is a dynamic programming approach to efficiently generate truncatable primes. It applies the concepts of subproblem overlap and optimal substructure:

### Subproblem Overlap
The code iteratively constructs truncatable primes by appending digits to existing primes. This leads to overlapping subproblems, as the process of finding truncatable primes of length `n-1` is utilized to generate primes of length `n`, which boosts the time effeciency of the code.

### Optimal Substructure
The optimal solution (a truncatable prime of length `n`) can be derived from optimal solutions of smaller subproblems (truncatable primes of length `n-1`). This property allows for a recursive or iterative bottom-up construction of the final solution.

### Old vs New Runtime

| Function | Old | New |
|   ---    |    ---   |    ---   |
|`LTPs(6)` |    19s   |   0.12s  |
|`LTPs(7)` |    493s   |  0.35s  |
|`RTPs(8)` |    1h+   |   0.03s  |

## Functions & Definitions
<section id="functions"> </section>

* `vect64` is the type used for an vector\<unsigned long long int\>.

* `uint64` is the type used for an unsigned long long int.

* `uint32` is the type used for unsigned int.

* `uint16` is the type used for unsigned short int.

* `uint8` is the type used for a unsigned char.

* `bool isPrime(uint64 num)` checks if num is prime.

* `bool isRTP(uint64 num)` checks if num is a right-truncatable prime (RTP).

* `bool isLTP(uint64 num)` checks if num is a left-truncatable prime (LTP).

* `bool isTSP(uint64 num)` checks if num is an RTP and an LTP at the same time (TP).

* `void RTPs(uint8 n)` outputs all n-digit right-truncatable primes. 

* `void LTPs(uint8 n)` outputs all n-digit left-truncatable primes. 

* `void TSPs(uint8 n)` outputs all n-digit two-sided primes (left truncatable and right truncatable at the same time).
<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contact
<section id="contact"> </section>

Belal - belal.hassan.kh@gmail.com, bilal.1021023@stemegypt.edu.eg

Project Link: [https://github.com/Belal-Hassan/Truncatable_Primes_Library](https://github.com/Belal-Hassan/Truncatable_Primes_Library.git)
<p align="right">(<a href="#readme-top">back to top</a>)</p>

[visual.js]: https://img.shields.io/badge/Visual-Studio?style=for-the-badge&logo=visual%20studio&logoColor=800080&labelColor=000000&color=000000
[visual-url]: https://visualstudio.microsoft.com
