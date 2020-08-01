# Acclaim

Acclaim is a foreground aware and size-sensitive reclaim scheme for Android. Acclaim consists of two parts: foreground aware eviction (FAE) and lightweight prediction-based reclaim scheme (LWP). FAE is used to relocate free pages from background applications to foreground applications. While LWP dynamically tunes the size and the amount of background reclaims according to the predicted allocation workloads.

Please cite the following paper if you use Acclaim:

Yu Liang, Jinheng Li, Rachata Ausavarungnirun, Riwei Pan, Liang Shi, Tei-Wei Kuo, Chun Jason Xue. "**Acclaim: Adaptive Memory Reclaim to Improve User Experience in Android Systems**". In Proceedings of the 2020 USENIX Annual Technical Conference (USENIX ATC 2020), Boston, MA, USA, July 2020.

[Paper](https://www.usenix.org/system/files/atc20-liang-yu_0.pdf) | [Talk Slides](https://www.usenix.org/system/files/atc20-paper932-slides-liang.pdf) | [Talk Video](https://www.usenix.org/conference/atc20/presentation/liang-yu) | [BibTeX](https://www.usenix.org/biblio/export/bibtex/254404)

```
@inproceedings {liang2020acclaim,
    author = {Yu Liang and Jinheng Li and Rachata Ausavarungnirun and Riwei Pan and Liang Shi and Tei-Wei Kuo and Chun Jason Xue},
    title = {Acclaim: Adaptive Memory Reclaim to Improve User Experience in Android Systems},
    booktitle = {2020 {USENIX} Annual Technical Conference ({USENIX} {ATC} 20)},
    year = {2020},
    isbn = {978-1-939133-14-4},
    pages = {897--910},
    url = {https://www.usenix.org/conference/atc20/presentation/liang-yu},
    publisher = {{USENIX} Association},
    month = jul,
}
```

## Source code tree overview

1. `kernel` contains the source code for Acclaim.
2. `benchmark` contains source code of micro benchmark for read and write.
3. `trace` contains the trace files and python scripts used to generate the Figure 12.
4. `doc` contains documents.

For more details, please see the `README.md` inside each subdirectory.

**NOTE**: The Acclaim source code currently distributed is almost completely contained in the `kernel` directory. The execptions are some small changes in the kernel's memory management system. More details can be found [here](doc/README.md).


## Contact Us

For further information please contact Ms LIANG Yu at `yliang22-c@my.cityu.edu.hk`. Drop us a note if you would like to use Acclaim in your research.
