/// url = https://tsch.js.org/3/play
type MyOmit<Record, Omits extends keyof Record> = {
  [Key in keyof Record as Key extends Omits ? never : Key]: Record[Key]
}