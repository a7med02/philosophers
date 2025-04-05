# 🧘 Philosophers - 42 Project

<p align="center">
  <img src="https://sdmntprsouthcentralus.oaiusercontent.com/files/00000000-b4a8-61f7-a049-f32f9c2974e2/raw?se=2025-04-05T23%3A45%3A53Z&sp=r&sv=2024-08-04&sr=b&scid=106f0605-f539-59f3-bf6b-82a27a8b972e&skoid=dfdaf859-26f6-4fed-affc-1befb5ac1ac2&sktid=a48cca56-e6da-484e-a814-9c849652bcb3&skt=2025-04-05T08%3A08%3A26Z&ske=2025-04-06T08%3A08%3A26Z&sks=b&skv=2024-08-04&sig=aJ7dXtAFTgHc6mCucos7u6a%2Bnu1wgSdTh8tHTOThBpE%3D" alt="Dining Philosophers Problem" width="600"/>
</p>

## 📘 About

**Philosophers** is a project at 42 School aimed at understanding the basics of **concurrent programming**, **mutexes**, and **thread safety** in C. Inspired by the famous **Dining Philosophers Problem**, this simulation challenges you to prevent **race conditions**, **deadlocks**, and **resource starvation**.

## 🧠 Objective

Simulate a group of philosophers who alternately eat, think, and sleep. Each philosopher must pick up two forks (shared resources) to eat but must avoid deadlock and starvation.

## 🛠 Technologies

- Language: C
- Threads: `pthreads` library
- Synchronization: Mutexes

## 📁 Project Structure

```
philosophers/
├── philo/               # Mandatory part
│   ├── philo.c
│   ├── init.c
│   ├── routine.c
│   ├── utils.c
│   ├── time.c
│   └── Makefile
├── philo_bonus/         # Bonus part (optional)
│   ├── philo_bonus.c
│   ├── init_bonus.c
│   ├── routine_bonus.c
│   ├── utils_bonus.c
│   └── Makefile
└── README.md
```

## 🔧 How to Compile

Clone and compile using `make`:

```bash
git clone https://github.com/a7med02/philosophers.git
cd philosophers/philo
make
```

For the bonus version (using semaphores and processes):

```bash
cd philosophers/philo_bonus
make
```

## 🚀 How to Run

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

📌 Example:

```bash
./philo 5 800 200 200
```

Arguments:

1. `number_of_philosophers`: how many philosophers are at the table.
2. `time_to_die`: time (in ms) a philosopher can go without eating before dying.
3. `time_to_eat`: time (in ms) a philosopher spends eating.
4. `time_to_sleep`: time (in ms) a philosopher spends sleeping.
5. `number_of_times_each_philosopher_must_eat`: optional; simulation stops when each philosopher has eaten this many times.

## 🎯 Goals

- Avoid deadlocks using smart resource allocation.
- Prevent starvation by ensuring all philosophers eat.
- Ensure accurate timing and clean output.

## ✍️ Project Requirements

- No data races or deadlocks.
- Precise timing.
- Must use pthreads (mandatory part) and semaphores (bonus).
- Clean and maintainable code.

## 📸 Screenshot

> Add your terminal output screenshot here if you'd like:

```bash
timestamp ms philosopher 1 is thinking
timestamp ms philosopher 1 has taken a fork
timestamp ms philosopher 1 has taken a fork
timestamp ms philosopher 1 is eating
...
```

## 📚 References

- [Dining Philosophers Problem – Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads (pthreads) Tutorial](https://computing.llnl.gov/tutorials/pthreads/)

---

## 👨‍💻 Author

- GitHub: [a7med02](https://github.com/a7med02)
- Portfolio: [https://medex-nine.vercel.app](https://medex-nine.vercel.app)
