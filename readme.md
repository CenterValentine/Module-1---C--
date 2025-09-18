# Overview

This CLI application allows text files to be parsed or tokenized in order to gather text based insights about the text document.  In the world of LLMs, word and language patterns are key and this application takes a basic but important step toward these actions.

{Provide a description of the software that you wrote to demonstrate the C++ language.}

{Describe your purpose for writing this software.}

{Provide a link to your YouTube demonstration. It should be a 4-5 minute demo of the software running and a walkthrough of the code. Focus should be on sharing what you learned about the language syntax.}

[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

The primary driver of developing this application was a study and focus on archtecture.  The goal was to plan out as much of the project as I could before starting in order to avoid blocks.  I even reviewed SLDC in order to examine and reflect on the impact my planning choices might have.

I used AI tools to provide articles, tutorials and research explaining basic C++ archetecure principles.  Much caution was taken when using AI to ensure the full learning experience and much time has been simple learning and relearning the language using simple resources, namely W3, to review beginnner to intermediate C++ concepts.

I looked at basic C++ project templates and tried to commit this structure to memory by adding it to my deep learning notes.

{Describe the tools that you used to develop the software}
I relied on *Obsidian* to develop the program architecture. I spent days planning out the application by slowing writing out classes, functions and data structures.  I completed the analyzis and   I sketched out the functions I thought I would use.  I would ask GPT about available functions for a problem to be solved.  

This methodical planned approach was by far the most successful I've ever had writing an application without major time-consuming errors.  Taking the time to plan things out lead to a deeper understanding of the application functionality, functions used and the ability to correct unforseen issues.

I relied heavily on W3's C++ documentation for most of my questions.  When I couldn't find to libary or concept I needed there I escalated to ChatGPT.

Stackoverflow helped me address high level concerns for how to start the application.

CMake was used to modularize the application.
ChatGPT was carefully used so that questions were asked about C++ principles.  If I had questions about the code, I would ask GPT to help me find a problem
I had ChatGPT craft C++ flashcards for Obsidian to solidify my understanding of C++ functions.  I also generated flashcards from the conversations I asked ChatGPT.





{Describe the programming language that you used and any libraries.}

# Useful Websites

{Make a list of websites that you found helpful in this project}

- [StackOverflow](https://stackoverflow.com/questions/5776910/what-does-pragma-once-mean-in-c)
- [StackOverflow - Architecture](https://stackoverflow.com/questions/2360734/whats-a-good-directory-structure-for-larger-c-projects-using-makefile)
- [Geeksforgeeks](https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/)
- [Web Site Name](http://url.link.goes.here)
- [Web Site Name](http://url.link.goes.here)

# Future Work

{Make a list of things that you need to fix, improve, and add in the future.}

- Size limitation protection:
- Line ending interpretation.
- Error handling:
    - Improper delimiters
    - bytes/hex detection:
        - Detects for indcations that a file is binary
    - bytes ≥128
    - very long lines.
    - memory cap on vectors (combined with file size restrictions)
- file type dilimiters (csv, txt, pdf)
- bytes/hex mode:
- UTF vs ASCII reporting
- Top-k analyzis
- LLM tokenization:
    - Convert text into tokens or vectorize tokens for LLM use.
