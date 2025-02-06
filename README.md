## Command line text searching and replacing tool

- Takes command line argument inputs.
- Takes directory/file path with substring to match and string to replace it with.
- Updates all occurrences of subtring we are searching for with replace string.
- For files, recursively searches every file and updates each file content that has matching substring.
- In case of overlapping matches, first occurrence is replaced.

### Command line arguments

<b> Read file/directory link </b> <br>

```
readlink -f <file/directory name>
```

<b> Execute in terminal </b> <br>

```
./cmd-txtreplace <file/folder full path> <target-text to match> <replace-text to replace with>
```

<b> Example </b> <br>

```
./cmd-txtreplace /home/rony/Documents/Dev/cmd-txtreplace/docs/ in "---REPLACED---"
```
