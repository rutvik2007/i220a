#!/usr/bin/env ruby

TABLE_BEGIN = <<'END_TABLE_BEGIN'
                       $HEADING
                       $UNDERLINE

$$$
\begin{array}{|c|c|c|c|}
\hline
\mathbf{Bits} & \mathbf{Exp} & \mathbf{Fraction} & \mathbf{Value}\\
\hline
END_TABLE_BEGIN

TABLE_END = <<'END_TABLE_END'
\hline
\end{array}
$$$

END_TABLE_END

def bit_field(v, msb, lsb)
  (v >> lsb) & ((1 << (msb - lsb + 1)) - 1)
end

N_PER_TABLE = 8

#output tables for IEEE floats having nTotalBits and nExpBits.
def do_float_tables(nTotalBits, nExpBits)
  nSignBits = 1
  nFracBits = nTotalBits - nSignBits - nExpBits

  expBias = 2**(nExpBits - 1) - 1
  fracScale = 2**nFracBits

  signField = [nTotalBits - 1, nTotalBits - 1 - nSignBits + 1]
  expField = [signField[1] - 1, signField[1] - 1 - nExpBits + 1]
  fracField = [expField[1] - 1, 0]

  heading =    "(#{nTotalBits}-#{nExpBits})-Bit Float Values Continued"
  underline = '='*heading.size
  tableBegin = TABLE_BEGIN
  tableBegin['$HEADING'] = heading
  tableBegin['$UNDERLINE'] = underline

  did_nan = false
  (0...(2**nTotalBits)).each do |v|
    puts tableBegin if v % N_PER_TABLE == 0
    s = bit_field(v, *signField)
    e = bit_field(v, *expField)
    f = bit_field(v, *fracField)
    exp = e - expBias
    s1 = (s == 0) ? '' : ' - '
    sign = (s == 0) ? ' + ' : ' - '
    value_fmt = '%12.6f'
    if e == 0 #denormalized
      value = ((2**(exp+1)) * f / fracScale)*1.0
      computation = "(#{s1}2^{#{exp + 1}}\\times(0 + #{f}/#{fracScale}))"
    elsif e == (2**nExpBits) - 1 #infinities, nan
      value = (f == 0) ? 'infinity' : 'nan'
      value_fmt = '%s'
      computation = ''
    else #normalized
      value = (2**exp) * (1.0 + f*1.0/fracScale)
      computation = "(#{s1}2^{#{exp}}\\times(1 + #{f}/#{fracScale}))"
    end
    puts sprintf "%1b\\;%0*b\\;%0*b & %6d & %6d & %s#{value_fmt} %s\\\\", 
                 s, nExpBits, e, nFracBits, f, e, f, sign, value, computation
    puts TABLE_END if v % N_PER_TABLE == (N_PER_TABLE - 1)
  end
end

USAGE = "usage: #{$0} N_TOTAL_BITS N_EXP_BITS\n" 

abort USAGE if ARGV.size != 2 || ARGV[0] !~ /^\d+$/ || ARGV[1] !~ /^\d+$/;
args = ARGV.map { |a| a.to_i }
abort USAGE if args[0] <= args[1]
do_float_tables(ARGV[0].to_i, ARGV[1].to_i);

