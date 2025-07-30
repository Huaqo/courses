# Contributing to SolarLytics

First off, thank you for your interest in contributing to **SolarLytics**!
This project is part of the Research Software Engineering course at the University of Potsdam and aims to calculate the theoretical energy production of German solar parks using open geographic and meteorological data.

Even though the project is currently maintained by a student group, we welcome all types of contributions and feedback from the broader community.

---

## Code of Conduct

This project and everyone participating in it is governed by the
[Code of Conduct](https://gitup.uni-potsdam.de/gottlebe/solarlytics/-/blob/main/CONDUCT.md).
By participating, you are expected to uphold this code. Please report unacceptable behavior
to [Mirjam Rupinski](mailto:rupinski@uni-potsdam.de).


## I Have a Questions
If you have a question or need clarification:

- First, check existing [issues](https://gitup.uni-potsdam.de/gottlebe/solarlytics/issues) — your question may have already been answered.
- If you don’t find a helpful thread, feel free to [open a new issue](https://gitup.uni-potsdam.de/gottlebe/solarlytics/issues/new).
- Include as much context as possible (e.g., error messages, system setup, relevant versions).

We’ll get back to you as soon as we can.


## What You Can Contribute

We appreciate contributions of all kinds, including (but not limited to):

- Suggestions for improvements
- Bug reports and fixes
- Code enhancements (efficiency, readability, modularity)
- Better error handling and logging
- Improvements to documentation and docstrings
- Workflow optimization (especially in Snakemake)
- Testing infrastructure

Please feel free to open an issue or pull request if you notice something that could be improved.


## Before You Start

- **Open an issue first**:\
    Please open an issue to discuss any major changes before submitting a pull request.
- **Keep your code clean and structured**:
  - Follow a modular and well-organized file structure.
  - Document all functions thoroughly with clear and complete docstrings.
  - Catch errors gracefully and log meaningful messages.
  - Design your code with testing in mind.
  - Consider how your additions integrate into the existing Snakemake workflows.

 An example of code that can be used for orientation can be found [here](https://gitup.uni-potsdam.de/gottlebe/solarlytics/-/wikis/Coding-Style-Example).



## Local Testing

The project provides a suite of unit tests for the various module functions — check the `tests/` folder. These tests can be run easily using:
```bash
pytest
```
When adding a new function, it is expected that an appropriate and comprehensive test is also created. This helps ensure the function remains reliable after future changes.


## Contributors

Currently, we track contributors in the *Contact* section of the [README](https://gitup.uni-potsdam.de/gottlebe/solarlytics/-/blob/main/README.md) file.

---

Thanks again for your interest and support!
— The SolarLytics Team
