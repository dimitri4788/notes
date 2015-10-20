Homebrew cheatsheet
===================

NOTE: If **--dry-run** or **-n** is passed, Homebrew will list all files which would be linked or which would be deleted by brew link --overwrite, but will not actually  link  or  delete any files.

Commands | Explanation
--- | ---
`$ brew install boost` | Install a package
`$ brew upgrade boost` | Upgrade a package
`$ brew unlink boost` | Unlink
`$ brew link boost` | Link
`$ brew switch boost 1.56.0` | Change versions
`$ brew list --versions boost` | See what versions you have
`$ brew info boost` | List versions, caveats, etc
`$ brew cleanup boost` | Remove old versions. By default, Homebrew does not uninstall old versions of a formula.
`$ brew edit boost` | Edit this formula
`$ brew home boost` | Open homepage
`$ brew list boost --verbose` | To see where all of the files are located, use the list [formula] --verbose
`$ brew uses --installed boost` | Before removing a formula, see what other installed formulae use it as a dependency
`$ brew remove --force boost` | Uninstall formulae and all their older versions
`$ brew pin boost` | To stop something from being updated/upgraded
`$ brew unpin boost` | To allow that formulae to update again

Global Commands | Explanation
--- | ---
`$ brew update` | Update the formulae and Homebrew itself
`$ brew list` | Lists the installed libraries
`$ brew outdated` | What’s due for upgrades?
`$ brew outdated --verbose` | What’s due for upgrades?
`$ brew upgrade` | Upgrade everything with this
`$ brew deps --installed` | Show the dependencies for all installed formulae
`$ brew deps --installed --tree` | Show the dependencies for all installed formulae as a tree
`$ brew cleanup -ns` | Show what will be removed by cleanup command, but do not actually remove anything
`$ brew cleanup -s` | Remove any older versions of installed formulae. Read more by doing `man brew`
`$ brew cleanup` | Clean up everything at once
`$ brew cleanup -n` | To see what would be cleaned up
`$ brew --cache` | Where does stuff get downloaded?



Sources
-------
- http://blog.shvetsov.com/2014/11/homebrew-cheat-sheet-and-workflow.html
- https://github.com/Homebrew/homebrew/blob/master/share/doc/homebrew/FAQ.md
