<h1 align="center">
  Get Next Line
</h1>

<p align="center">
	<b><i>42 Project - Reading a line from a file descriptor</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Juh-B/42_Get_Next_Line?color=lightblue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Juh-B/42_Get_Next_Line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/Juh-B/42_Get_Next_Line?color=green" />
</p>

This project is part of the 42 School curriculum and its goal was to **implement the `get_next_line` function**, which reads and returns a line from a given file descriptor.  

In C programming, reading text line by line is not straightforward. `get_next_line` solves this by:  
- Handling partial reads with a configurable buffer size (`BUFFER_SIZE`)  
- Managing memory dynamically for lines of any length  
- Preserving state between calls using **static variables**  
- Supporting multiple file descriptors simultaneously (bonus part)  

The result is a reusable function often integrated into larger projects, teaching important concepts such as **buffer management, memory safety, and static storage duration.**


## Tech Stack

- **Language:** C  
- **Build Tool:** Makefile (`-Wall -Wextra -Werror -D BUFFER_SIZE=n`)  
- **Norm:** 42 coding standard (Norminette)  
- **Version Control:** Git  


## Installation

Clone the repository:

```bash
git clone https://github.com/Juh-B/42_Get_Next_Line.git
cd 42_Get_Next_Line
```

Compile manually, defining the buffer size with `-D BUFFER_SIZE=n`:

_Mandatory version_

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

_Bonus version_

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```


## Usage

_Example usage:_

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```


## Features

| Feature	| Description |
|---------|-------------|
| Line Reading | Reads a line from a given file descriptor, including `\n` when present |
| Configurable Buffer	| Uses a customizable buffer size via `BUFFER_SIZE` macro |
| Static Variables | Maintains reading state between function calls |
| Memory Safety	| Dynamically allocates and frees memory for each line |

**Bonus Features**

| Feature	| Description |
|---------|-------------|
| Single Static Variable | Implemented using only one static variable |
| Multiple FDs Support | Handles multiple file descriptors at the same time without losing context |

_Example_ – Reading from stdin with small buffer:

```bash
echo -e "Line 1\nLine 2\nLine 3" | ./gnl_program
```

Output:

```scss
Line 1
Line 2
Line 3
```


## Learning Outcomes

Through Get Next Line, I improved my skills in:

- Efficient file reading and buffer management in C
- Proper usage of static variables to preserve state
- Handling dynamic memory allocation and avoiding leaks
- Writing modular code split into `.c` and `.h` files
- Building reusable functions applicable to future projects
