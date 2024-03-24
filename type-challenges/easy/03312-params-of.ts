/// url = https://tsch.js.org/3312/play
type Unreachable = never;
type ParamsOf<Func extends (...args: any[]) => unknown> = Func extends (
  ..._: infer Params
) => unknown
  ? Params
  : Unreachable;