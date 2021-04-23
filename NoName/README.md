# NoName Codebook #

ICPC Codebook used by the team NoName@NTU. ([Latest PDF](https://gitlab.com/nonamentu/codebook/-/jobs/artifacts/master/file/codebook.pdf?job=pdf_build))

## NoName Related Links ##

- <https://github.com/ltf0501/NoName/>

## TODOs ##

See <https://hackmd.io/jJ5AXvnzRKaJMXLmlEfgCQ?view>.

## Coding Style ##

See <https://hackmd.io/YmmIGclyS8GDoQsZdrc-Iw?view> (not yet complete).

Note that for the snippets in the codebook, our style is slightly altered to save space. See `.clang-format` for details.

## Sources ##

Some of the codes in this repo may not be original, in which case we would try our best to list the source in the `references` column of the YAML headers. However, some snippets may have sat in our libraries for a long time, and is difficult to find the source for. If you feel that you are the author for a piece of code and would like to be acknowledged, feel free to file an issue.

## Test for Compilation Warnings & Errors ##

To test for compilation warnings and errors, run `testcompile.fish`. Note that `fish` and `clang++` is required.

(Since some paths are currently hardcoded in this script, it is not yet upstreamed.)

# Original README #
# Codebook Template

A codebook template for ICPC contests utilizing Jekyll and Pandoc, used by the team NoName@NTU.

## Dependencies
- Jekyll
- Pandoc
- Xelatex
- Related fonts

## How To

### Adding an category

Suppose that we would like to add a category titled "Graph" with the id `graph`. We can add the following YAML snippet under `collections` in the file `_config.yml`.

``` yaml
  graph:
    title: "Graph"
```

Then, create the directory `_graph/`.

### Adding a code snippet

Under the directory that corresponds to the category you would like to place the snippet in, create a directory with an arbitrary name. Under the directory, create the file `index` with the following content:

``` md
---
title: "The Title of the Snippet"
libpath: "_path_to_the_snippet_source.cpp"
testpath: "_path_to_the_test_source.cpp"
---

Whatever textual content, *supports Markdown syntax*.
```

Note that `libpath`, if not specified, defaults to `_lib.cpp`, and `testpath` defaults to `_test.cpp`.

It then remains to place the source code under the specified path. Note that the test file will not be displayed in the final PDF, and exists only for automatic testing, a possible future feature.

### PDF Generation

Run `./build.sh` to generate the codebook PDF at `codebook.pdf`.

## TODO

- Automatic tests
