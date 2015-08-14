libgvps
---

libgvps stands for *Generic Viterbi Path Searcher*.

This library is an implementation of Viterbi algorithm on a *probabilistic* formulation that helps you **find the most likely sequence given a set of states or candidates over a certain time period and the state transition probabilities**.

libgvps allows the states/candidates space to be dense or sparse or even circular; transition probabilities can be either static or dynamic as opposed to time.

| Function | Suggested use cases | Examples (if any)
| --- | --- | --- |
| `gvps_sparse_sampled` | path searching on a plane
| `gvps_sparse_sampled_hidden` | path searching with skips
| `gvps_sparse_sampled_static` | path searching on a plane assuming time locality of trans. prob
| `gvps_sparse_sampled_hidden_static` | path searching with skips assuming time locality of trans. prob | F0 tracking
| `gvps_sparse_circular` | path searching on a cylinder
| `gvps_sparse_circular_hidden` | path searching on a cylinder with skips
| `gvps_sparse_circular_static` | path searching on a cylinder assuming time locality of trans. prob
| `gvps_sparse_circular_hidden_static` | path searching on a cylinder with skips assuming time locality of trans. prob
| `gvps_full_sampled` | path searching on a plane
| `gvps_full_sampled_hidden` | path searching with skips
| `gvps_full_sampled_static` | path searching on a plane assuming time locality of trans. prob | (lowpass-like) filtering on a discrete/quantized signal
| `gvps_full_sampled_hidden_static` | path searching with skips assuming time locality of trans. prob
| `gvps_full_circular` | path searching on a cylinder
| `gvps_full_circular_hidden` | path searching on a cylinder with skips
| `gvps_full_circular_static` | path searching on a cylinder assuming time locality of trans. prob
| `gvps_full_circular_hidden_static` | path searching on a cylinder with skips assuming time locality of trans. prob
| `gvps_full` | path searching on a (special) plane with arbitrary geometric assumptions
| `gvps_full_static` | path searching on a (special) plane with arbitrary geometric assumptions, assuming time locality of trans. prob | MAP inference for Hidden Markov Models
| `gvps_variable` | path searching in an arbitrary space | unit selection speech synthesis
