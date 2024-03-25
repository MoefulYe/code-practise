/// url = https://tsch.js.org/10/play

type TupleToUnion<Tuple extends readonly any[]> = Tuple extends [
  infer Head,
  ...infer Rest
]
  ? Head | TupleToUnion<Rest>
  : never;
