# High-priority graph subtopics (master these first)

1. **BFS / DFS (and variants)** — basic traversal, multi-source BFS, BFS on grids, 0-1 BFS (for edge weights 0/1). Fundamental for many modeling problems. ([CSES][1], [MSU Computer Science][2])
2. **Single-source shortest paths** — Dijkstra (priority queue optimizations), 0-1 BFS, Bellman–Ford (negative edges), shortest path on DAGs. These are extremely common. ([CSES][1], [Memgraph][3])
3. **Trees — basics + tree DP** — subtree DP, rerooting, diameter, and common tree queries. These show up a lot as “graph” problems disguised as tree problems. ([MSU Computer Science][2])
4. **Lowest Common Ancestor (LCA)** — binary lifting, Euler tour + RMQ; a must for path queries on trees. ([MSU Computer Science][2])
5. **Disjoint Set Union (Union-Find)** — connectivity, offline merging, DSU on trees (useful trick). Fast to implement and appears frequently. ([Codeforces][4])
6. **Strongly Connected Components (SCC) & condensation DAG** — Kosaraju, Tarjan, and using SCCs to simplify directed-graph problems. ([Codeforces][4])
7. **Topological sort & DAG DP** — counting/longest path in DAGs, DP after topo order. ([Codeforces][4])
8. **MST (Kruskal / Prim) + DSU applications** — Kruskal with DSU, second-best MST patterns. ([Codeforces][4])
9. **Bridges & articulation points / edge & vertex criticality** — Tarjan’s lowlink for cut-edge / cut-vertex. Useful in network-robustness problems. ([MSU Computer Science][2])
10. **Max Flow & Bipartite Matching** — Dinic, Hopcroft–Karp, basic min-cost flow awareness for modeling (used less often than shortest paths/DP but shows in harder problems). ([Codeforces][4])

---

# Medium / advanced (learn after the above)

* **Tree decompositions / centroid decomposition** (useful for some heavy problems). ([GitHub][5])
* **Heavy-Light Decomposition (HLD)** (path queries with segment trees — appears moderately). ([GitHub][5])
* **Graph + DP patterns**: bitmask DP on small vertex sets, state augmentation `(node,mask)` search. ([NC DOCKS][6])
* **Graph modeling patterns**: building state graphs (encode extra state into node), reverse graphs, meet-in-the-middle for path problems. ([MSU Computer Science][2])
* **Special algorithms (Stoer-Wagner min-cut, dynamic connectivity, link-cut trees)** — *rare* in prelims; useful for very hard problems or finals.

---

# Low priority for prelims (skip unless you have extra time)

* Planarity tests, full graph isomorphism, very heavy advanced topics (unless you aim for regionals/world finals).

---

# Quick 2-month (8-week) study plan — focused on prelims

(Goal: strong implementation + pattern recognition for top-frequency topics.)

Weeks 1–2 — Foundations & traversal

* Read/implement BFS, DFS, multi-source BFS, 0-1 BFS.
* Solve 20 problems: grid BFS, shortest unweighted path, connectivity, easy tree traversals.
* Time split: 60% practice, 40% implementation drills (templates).

Weeks 3–4 — Shortest paths & DSU

* Implement Dijkstra (with binary-heap), Bellman-Ford, and DSU.
* Solve 20 problems: Dijkstra variants, multi-source shortest path, DSU problems (Kruskal, connectivity queries).
* Do 2 timed mini-contests (1.5 hrs each).

Weeks 5–6 — Trees, LCA, Tree DP

* Implement LCA (binary lifting) and basic rerooting DP patterns.
* Solve 20 problems: path queries, subtree DP, diameter, rerooting problems.
* Practice one harder problem each week (tree + DP mix).

Weeks 7–8 — Flow, SCC, bridges, advanced patterns

* Implement Kosaraju/Tarjan, Dinic (or Hopcroft–Karp for matching). Study bridges/articulation points.
* Solve 15–20 problems: SCC reductions, matching, bridge problems, a mix of harder graph+dp modeling tasks.
* Final 2 full-length mock prelims (2–3 hrs), review incorrect solutions.

Daily micro-targets (throughout): 1–2 contest problems/day + 30–40 min template/implementation practice. Focus on clean, reusable templates for Dijkstra, DSU, LCA, and Dinic.

(If you want, I can convert this into a day-by-day calendar with specific problem picks from Codeforces/CSES/AtCoder.)

---
