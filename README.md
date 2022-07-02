# Introduction
```ac_matcher``` is a simple Excel Add-in written in VBA and C++ which has two macros for pattern matching with Aho-Corasick algorithm.

# Macros

```visualbasic
xlut_MATCH(ByVal value As String, ByVal patternRange As Range, Optional ByVal longestLeft As Boolean = False) As Variant
```

Works like [MATCH](https://support.microsoft.com/en-us/office/match-function-e8dffd45-c762-47d6-bf89-533f4a37673a). If ```longestLeft``` is ```True```, returns the index of longest matched pattern.

```visualbasic
xlut_VLOOKUP(ByVal value As String, ByVal patternRange As Range, ByVal columnIndex As Long, Optional ByVal longestLeft As Boolean = False) As Variant
```

Works like [VLOOKUP](https://support.microsoft.com/en-us/office/vlookup-function-0bbc8083-26fe-4963-8ab8-93a18ad188a1). If ```longestLeft``` is ```True```, returns the index of longest matched pattern.

# NOTE
To speed up the lookup, the patterns given by the Range are cached which means the function result won\'t reflect the changes you make to the patterns.