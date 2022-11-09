

//--------------------------------------------------------------------------
#ifndef apalha_EOS_H
#define apalha_EOS_H
//--------------------------------------------------------------------------

namespace apalha{
  class eos_base{
  public:
    int type;
    eos_base();

    virtual void evaluate() = 0;
  };

  class eos_A : public eos_base {
  public:
    eos_A();

    void evaluate();
  };

  class eos_B : public eos_base {
  public:
    eos_B();

    void evaluate();
  };
}

//--------------------------------------------------------------------------
#endif  // apalha_EOS_H
//--------------------------------------------------------------------------
