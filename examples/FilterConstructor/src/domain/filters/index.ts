import { ColorMatrices } from '../../services'
import { filterControlConstraints, filters, matrix } from './filters'

export const Filters = {
  filters,
  filterControlConstraints,
  matrix: matrix(ColorMatrices)
} as const

export type Filters = typeof Filters
export * from './types'
