# Neural Network C++

This project starts from my previous project [Neural Network Overview](https://github.com/Herosteve0/Neural-Network-Overview),which explored neural network
implementations in **C#**. We'll be exploring Neural Networks in the context of **C++**, along with raw Cuda instead of C#'s ILGPU auto compiling.

I highly recommend you check out [Neural Network Overview](https://github.com/Herosteve0/Neural-Network-Overview) as it dives deeper into the math and logic
behind it, whilst here I plan to focus on pure performance.

I also want to add, I have no prior experience to C++ besides knowing it's a hard language to Master, so I plan to devlog a good portion of my recovery
from the C# project to this one, for anyone interested in learning C++ and somehow stumbled upon this repository.

# Devlog

---
For starters, I began working on the Tensor logic, since it's one of the few classes that doesn't rely on other classes. I learnt abstraction and templates
through it. Abstraction being a bit weird at first, but rather straight forward, while templates are apparently a generic class type that is compiled into types.

I also learnt a few things about the format. For starters, you create the structure of the class in the header file (.h) and the code for each function in the
actual code file (.cpp), where you include the header file and prefix each function with its class' name. As for generic classes, due to the compilation issues,
you can't use the code cpp file for the code. so instead, you either put the code in the header file which, if it's bad practice for the normal classes, I
personally think it's bad practice for the generic type ones too. So the other solution is using a .hpp class for the code, and you include it at the end of the
header file. It's the format I've chosen and... it's fun, honestly.

A few more quick notes, I made my own random just so I have more familiar functions. Apparently, **std::vector** here is an array with whatever input you give it,
whereas **std::array** is a vector with an expected size. **std::span** is an unowning memory array, similar to the C# project. **std::initializer_list**... I'll
be honest, I haven't understood this yet, I just use it as... well... an initializer list. Lastly, memory is almost self-handled. It is freed upon exiting its
code block, which mean a local variable will be freed once the function stops, class variables are freed when the function is freed, etc. I haven't found an
instance where I do need to free my own memory, so I am not familiar with any scenarios in which I'll need to (excluding the GPU) as of now.
---