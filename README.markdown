# BMDSwitcherMock
Mocking COM so that developers can develop applications built against Blackmagic Design's BMDSwitcherAPI without having to be attached to an ATEM switcher.
This is a work in progress.

## Goals
* Be binary compatible with Blackmagic Design's BMDSwitcherAPI
* Compile a valid COM binary on OSX and Windows
* Satisfy the ATEM Software Control application. ;)

### What Doesn't Work
A better question is, "What does work?".
Creating an ABI compatable COM isn't that difficult, especially not when targeting only the public SDK.
Unfortunately, the harder part is writing the mock in such a way that it behaves in a realistic maner.

### Contact
Terin Stock
[@terinjokes](http://twitter.com/terinjokes)
[terin@terinstock.com](mailto:terin@terinstock.com)