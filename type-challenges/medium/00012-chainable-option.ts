/// url = https://tsch.js.org/12/play

type Chainable<Options = {}> = {
  get(): Options;
  option<Key extends Exclude<string, keyof Options>, Value>(
    key: Key,
    value: Value
  ): Chainable<Options & Record<Key, Value>>;
};