# Search Engine Project

A lightning-speed search engine designed to sift through extensive datasets and find matching documents efficiently.

## Features

- **Speedy Data Parsing**: Efficiently parse vast datasets, categorizing by ID and document. The parsed data is stored using the `Map` data structure for quick access.

- **Advanced Data Storage**:
  - Utilize the `Trie` data structure to store every distinct word from the documents.
  - Leverage the `Listnode` structure to keep track of each word's occurrences across different documents and its frequency.

- **Robust Sorting Mechanism**:
  - The engine employs a `Maxheap` to sort and rank documents that match the user input.
  - The documents are ranked based on a similarity score, ensuring the most relevant results are displayed at the top.

## How it Works

1. **Data Parsing**: The engine first processes the datasets, segregating them by ID and the content of the document. This step ensures quick access and retrieval of documents when needed.

2. **Data Storage**: Post parsing, every word from the documents is stored using the Trie data structure. Additionally, each word's frequency and the documents it appears in are stored using the Listnode structure.

3. **Searching and Ranking**: Upon receiving a user input or query, the engine sifts through the stored data to find matching documents. The found documents are then sorted and ranked using a Maxheap based on their similarity score to the query.

With the combination of advanced data structures and efficient algorithms, this search engine ensures rapid and accurate results even with vast datasets.


