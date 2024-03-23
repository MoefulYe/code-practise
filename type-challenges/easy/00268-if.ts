/// url = https://www.typescriptlang.org/play?#code/PQKgUABBBMBsAcEC0ECSAzSyk91gRgJ4QAKAhgG4CmANhAOI0CuAzgBYDWA9hRABQABAA5l2TAC4cAlBADEVUcVkSAljRZgss7RACKTKi3EquAO01RUAWyE0qVqqfERxbKhFV1xhIe4AGGAA8AMIANBAAKuEAYgB8fhAA7mwqAMZsEGSpqVRC4iwQqWYAJirGZhB+wX7hZC4AThJsxBRkzP4RNZmmxZkQ6G0sLW0GldF+AHSV1RAqBVQAHr6p4lS94lwQ+O5UZW71leKNVAlcB34D6idJKXaVnd29fuOFZKZb7m-E3r4TFhDRM4QRZkGx2ABc-z80PyWB+7gAghAALxodCBI4GcIAcjI2Jx+GxsSgwGAwKWVBWaxcm22EFx2LhPncACEUWjApcWFQcXiCUSIKTyctVutae5sYSsNC-P9iQA1FRURIQCr0MoACSY+HBEDY4nEQhY4NJ+XSEwAViwJmcAObAODwMAgYCaUAQAD6Xu9Pu9EAAmlwmAdglxiu4NVR6u5fbGvRAXZp4RywpEYsTUV83SBPXHfZFDM5gqJDLm837EyobGdnMmAN4QACiAEcmG1wo2KSsIABffr1LhWekCeFIdJtOymW2GYCeFiMsDJ1IlgqogDaWE7IsCLbbNECQUxPPpfPphNivKJF83XfEO9bbQP6K5x4Z4WgF5gsWvAF03WSRxYJBFhFYD6gHepF2ZYFwKBVEglMJgaBoS9+VibMy3LD0AWDVwowgABlVYjUw8sE1dUAsGJAi2DIaMIEIIMDhYLhmHKUxjT1A0jRNYAzTYS1rTtB0EGAN4WESKMqIgRVlQgFi2JMDjdX1Q1jVNFhzStG16ntR1gAU1QzA0KBiQAWTOdxglo5DHGnTjVJ4jStKE3TnVdIA

type If<Pred extends boolean, TrueCond, FalseCond> = Pred extends true
  ? TrueCond
  : FalseCond;
