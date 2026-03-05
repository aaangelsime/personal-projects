"""
Linear Independence Visualizer using Manim
==========================================
Demonstrates linear independence and dependence of vectors
using 2D geometric visualizations and matrix representations.

Run with:
    manim -pql linear_independence.py LinearIndependenceScene
    manim -pqh linear_independence.py LinearIndependenceScene   # high quality
"""

from manim import *
import numpy as np


# ─── Color palette ───────────────────────────────────────────────────────────
C_V1      = BLUE
C_V2      = YELLOW
C_SPAN    = GREEN
C_DEP     = RED
C_INDEP   = GREEN
C_TITLE   = WHITE
C_MATRIX  = ORANGE


# ─── Helper: build matrix + det panel (standalone, usable by any scene) ──────
def build_matrix_panel(v1, v2, independent):
    mat = MathTex(
        r"A = \begin{pmatrix}"
        + f"{v1[0]} & {v2[0]}\\\\"
        + f"{v1[1]} & {v2[1]}"
        + r"\end{pmatrix}",
        color=C_MATRIX,
    )
    det_val = int(v1[0] * v2[1] - v1[1] * v2[0])
    det_tex = MathTex(
        r"\det(A) = "
        + f"{v1[0]}\\cdot{v2[1]} - {v1[1]}\\cdot{v2[0]} = {det_val}",
        color=C_MATRIX,
    ).scale(0.75).next_to(mat, DOWN, buff=0.35)

    color = C_INDEP if independent else C_DEP
    verdict = Text(
        "✓ INDEPENDENT" if independent else "✗ DEPENDENT",
        font_size=26, color=color,
    ).next_to(det_tex, DOWN, buff=0.35)

    box = SurroundingRectangle(
        VGroup(mat, det_tex, verdict), color=color, buff=0.2
    )
    return VGroup(mat, det_tex, verdict, box)


# ─── Helper: draw a labeled vector ───────────────────────────────────────────
def make_vector(scene_axes, direction, color, label_str, label_side=UR):
    """Return (arrow, label) for a 2-D vector plotted on axes."""
    arr = Arrow(
        scene_axes.c2p(0, 0),
        scene_axes.c2p(*direction),
        buff=0,
        color=color,
        stroke_width=4,
        max_tip_length_to_length_ratio=0.15,
    )
    lbl = MathTex(label_str, color=color).scale(0.75)
    lbl.next_to(arr.get_end(), label_side, buff=0.12)
    return arr, lbl


# ─── Scene 1: Title card ──────────────────────────────────────────────────────
class TitleScene(Scene):
    def construct(self):
        title = Text("Linear Independence", font_size=56, color=C_TITLE)
        subtitle = Text(
            "A visual intuition with matrices", font_size=30, color=GRAY
        ).next_to(title, DOWN, buff=0.4)

        formula = MathTex(
            r"\vec{v}_1, \vec{v}_2 \text{ independent} "
            r"\iff \det\begin{pmatrix}| & |\\ \vec{v}_1 & \vec{v}_2\\ | & |\end{pmatrix} \neq 0",
            color=C_MATRIX,
        ).scale(0.8).next_to(subtitle, DOWN, buff=0.6)

        self.play(Write(title), run_time=1.2)
        self.play(FadeIn(subtitle, shift=UP * 0.3))
        self.play(Write(formula), run_time=1.5)
        self.wait(2)
        self.play(FadeOut(VGroup(title, subtitle, formula)))


# ─── Scene 2: Linearly INDEPENDENT vectors ────────────────────────────────────
class IndependentVectorsScene(Scene):
    def construct(self):
        # --- heading ---
        heading = Text("Linearly Independent Vectors", font_size=36, color=C_INDEP)
        heading.to_edge(UP)
        self.play(Write(heading))

        # --- axes ---
        axes = Axes(
            x_range=[-0.5, 4, 1], y_range=[-0.5, 4, 1],
            x_length=5, y_length=5,
            axis_config={"include_tip": True, "color": GRAY},
        ).shift(LEFT * 2)
        self.play(Create(axes))

        # vectors
        v1 = np.array([3, 1])
        v2 = np.array([1, 3])
        arr1, lbl1 = make_vector(axes, v1, C_V1, r"\vec{v}_1", UR)
        arr2, lbl2 = make_vector(axes, v2, C_V2, r"\vec{v}_2", UL)

        self.play(GrowArrow(arr1), FadeIn(lbl1))
        self.play(GrowArrow(arr2), FadeIn(lbl2))
        self.wait(0.5)

        # --- span parallelogram ---
        corners = [
            axes.c2p(0, 0),
            axes.c2p(*v1),
            axes.c2p(*(v1 + v2)),
            axes.c2p(*v2),
        ]
        para = Polygon(*corners, fill_color=C_SPAN, fill_opacity=0.2,
                       stroke_color=C_SPAN, stroke_width=1.5)
        span_lbl = Text("span = ℝ²", font_size=22, color=C_SPAN).move_to(
            axes.c2p(*(0.5 * (v1 + v2)))
        )
        self.play(DrawBorderThenFill(para), FadeIn(span_lbl))
        self.wait(0.5)

        # --- matrix + determinant panel ---
        mat_group = build_matrix_panel(v1, v2, independent=True)
        mat_group.to_edge(RIGHT).shift(UP * 0.3)
        self.play(FadeIn(mat_group, shift=LEFT * 0.3))
        self.wait(2)

        self.play(FadeOut(VGroup(axes, arr1, lbl1, arr2, lbl2,
                                  para, span_lbl, heading, mat_group)))


# ─── Scene 3: Linearly DEPENDENT vectors ─────────────────────────────────────
class DependentVectorsScene(Scene):
    def construct(self):
        heading = Text("Linearly Dependent Vectors", font_size=36, color=C_DEP)
        heading.to_edge(UP)
        self.play(Write(heading))

        axes = Axes(
            x_range=[-0.5, 4, 1], y_range=[-0.5, 4, 1],
            x_length=5, y_length=5,
            axis_config={"include_tip": True, "color": GRAY},
        ).shift(LEFT * 2)
        self.play(Create(axes))

        v1 = np.array([2, 1])
        v2 = np.array([4, 2])   # v2 = 2·v1  → dependent

        arr1, lbl1 = make_vector(axes, v1, C_V1, r"\vec{v}_1", UR)
        arr2, lbl2 = make_vector(axes, v2, C_V2, r"\vec{v}_2 = 2\vec{v}_1", UR)

        self.play(GrowArrow(arr1), FadeIn(lbl1))
        self.play(GrowArrow(arr2), FadeIn(lbl2))
        self.wait(0.3)

        # highlight they lie on the same line
        line = axes.plot(
            lambda x: 0.5 * x,
            x_range=[0, 4.2],
            color=C_DEP, stroke_width=2, stroke_opacity=0.6,
        )
        line_lbl = Text("same line (1-D span)", font_size=20, color=C_DEP).move_to(
            axes.c2p(3.5, 2.2)
        )
        self.play(Create(line), FadeIn(line_lbl))
        self.wait(0.5)

        # matrix panel
        mat = MathTex(
            r"A = \begin{pmatrix}2 & 4\\1 & 2\end{pmatrix}", color=C_MATRIX
        )
        det_tex = MathTex(
            r"\det(A) = 2\cdot2 - 4\cdot1 = 0", color=C_MATRIX
        ).scale(0.75).next_to(mat, DOWN, buff=0.35)
        verdict = Text("✗ DEPENDENT  (det = 0)", font_size=26, color=C_DEP).next_to(
            det_tex, DOWN, buff=0.35
        )
        box = SurroundingRectangle(
            VGroup(mat, det_tex, verdict), color=C_DEP, buff=0.2
        )
        panel = VGroup(mat, det_tex, verdict, box).to_edge(RIGHT).shift(UP * 0.3)

        self.play(FadeIn(panel, shift=LEFT * 0.3))

        # flash det = 0
        self.play(Indicate(det_tex, color=RED, scale_factor=1.15))
        self.wait(2)

        self.play(FadeOut(VGroup(axes, arr1, lbl1, arr2, lbl2,
                                  line, line_lbl, heading, panel)))


# ─── Scene 4: Interactive determinant sweep ───────────────────────────────────
class DeterminantSweepScene(Scene):
    """
    Animate v2 rotating while the determinant value updates in real time,
    showing the transition between independent ↔ dependent.
    """

    def construct(self):
        heading = Text("Determinant & Dependence", font_size=34, color=C_TITLE)
        heading.to_edge(UP)
        self.play(Write(heading))

        axes = Axes(
            x_range=[-3.5, 3.5, 1], y_range=[-3.5, 3.5, 1],
            x_length=6, y_length=6,
            axis_config={"include_tip": True, "color": GRAY},
        ).shift(LEFT * 1.5)
        self.play(Create(axes))

        v1 = np.array([2.0, 0.5])
        R = 2.5   # radius for v2

        # fixed v1 arrow
        arr1 = Arrow(
            axes.c2p(0, 0), axes.c2p(*v1),
            buff=0, color=C_V1, stroke_width=4,
            max_tip_length_to_length_ratio=0.15,
        )
        lbl1 = MathTex(r"\vec{v}_1", color=C_V1).scale(0.8).next_to(
            arr1.get_end(), UR, buff=0.12
        )
        self.play(GrowArrow(arr1), FadeIn(lbl1))

        # det readout
        det_display = VGroup()
        det_label = Text("det(A) = ", font_size=28, color=C_MATRIX)
        det_value = DecimalNumber(0, num_decimal_places=2, color=YELLOW,
                                   font_size=32)
        det_label.to_edge(RIGHT).shift(UP * 2)
        det_value.next_to(det_label, RIGHT, buff=0.1)
        det_display.add(det_label, det_value)
        self.play(FadeIn(det_display))

        # sweep v2 through 360°
        num_steps = 120
        angles = np.linspace(0, 2 * np.pi, num_steps + 1)

        prev_arr2 = None
        prev_lbl2 = None
        prev_fill  = None

        for i, theta in enumerate(angles):
            v2 = R * np.array([np.cos(theta), np.sin(theta)])
            det_val = v1[0] * v2[1] - v1[1] * v2[0]

            color = interpolate_color(C_INDEP, C_DEP,
                                      1 - abs(det_val) / (R * np.linalg.norm(v1) + 1e-9))

            new_arr2 = Arrow(
                axes.c2p(0, 0), axes.c2p(*v2),
                buff=0, color=color, stroke_width=4,
                max_tip_length_to_length_ratio=0.15,
            )
            v2_3d = np.array([v2[0], v2[1], 0.0])
            new_lbl2 = MathTex(r"\vec{v}_2", color=color).scale(0.7).next_to(
                new_arr2.get_end(), normalize(v2_3d) * 0.3 + UP * 0.1, buff=0.12
            )

            # parallelogram fill
            corners = [
                axes.c2p(0, 0), axes.c2p(*v1),
                axes.c2p(*(v1 + v2)), axes.c2p(*v2),
            ]
            new_fill = Polygon(
                *corners,
                fill_color=color, fill_opacity=max(0.05, abs(det_val) / 6),
                stroke_width=0,
            )

            if i == 0:
                self.add(new_fill, new_arr2, new_lbl2)
            else:
                self.remove(prev_fill, prev_arr2, prev_lbl2)
                self.add(new_fill, new_arr2, new_lbl2)

            det_value.set_value(det_val)
            det_value.set_color(color)

            prev_arr2, prev_lbl2, prev_fill = new_arr2, new_lbl2, new_fill
            self.wait(0.03)

        self.wait(1.5)
        self.play(FadeOut(VGroup(axes, arr1, lbl1,
                                  prev_arr2, prev_lbl2, prev_fill,
                                  det_display, heading)))


# ─── Scene 5: 3-vector dependence in 3D ──────────────────────────────────────
class ThreeDDependenceScene(ThreeDScene):
    def construct(self):
        self.set_camera_orientation(phi=65 * DEGREES, theta=-45 * DEGREES)

        axes = ThreeDAxes(
            x_range=[-3, 3], y_range=[-3, 3], z_range=[-3, 3],
            x_length=6, y_length=6, z_length=6,
            axis_config={"color": GRAY},
        )
        self.play(Create(axes))

        # --- Three INDEPENDENT vectors ---
        vecs_indep = [
            (np.array([2, 0, 0]), BLUE,   r"\vec{v}_1"),
            (np.array([0, 2, 0]), YELLOW, r"\vec{v}_2"),
            (np.array([0, 0, 2]), GREEN,  r"\vec{v}_3"),
        ]
        arrows_indep = []
        for v, col, _ in vecs_indep:
            a = Arrow3D(ORIGIN, v, color=col, thickness=0.03)
            arrows_indep.append(a)
            self.play(Create(a), run_time=0.5)

        title_i = Text("3 Independent vectors → span ℝ³",
                        font_size=28, color=C_INDEP).to_edge(UP)
        self.add_fixed_in_frame_mobjects(title_i)
        self.play(Write(title_i))
        self.begin_ambient_camera_rotation(rate=0.25)
        self.wait(3)
        self.stop_ambient_camera_rotation()

        self.play(FadeOut(VGroup(*arrows_indep, title_i)))

        # --- Three DEPENDENT vectors (all in xy-plane) ---
        vecs_dep = [
            (np.array([2, 0, 0]),   C_V1, r"\vec{v}_1"),
            (np.array([0, 2, 0]),   C_V2, r"\vec{v}_2"),
            (np.array([2, 2, 0]),   C_DEP, r"\vec{v}_3=\vec{v}_1+\vec{v}_2"),
        ]
        arrows_dep = []
        for v, col, _ in vecs_dep:
            a = Arrow3D(ORIGIN, v, color=col, thickness=0.03)
            arrows_dep.append(a)
            self.play(Create(a), run_time=0.5)

        # shade the xy-plane
        plane = Square(side_length=5, fill_color=C_DEP, fill_opacity=0.15,
                       stroke_width=0).rotate(PI / 2, axis=RIGHT)
        self.play(FadeIn(plane))

        title_d = Text("3 Dependent vectors → span only ℝ²",
                        font_size=28, color=C_DEP).to_edge(UP)
        self.add_fixed_in_frame_mobjects(title_d)
        self.play(Write(title_d))
        self.begin_ambient_camera_rotation(rate=0.25)
        self.wait(3)
        self.stop_ambient_camera_rotation()

        self.play(FadeOut(VGroup(*arrows_dep, plane, title_d, axes)))


# ─── Scene 6: Summary card ────────────────────────────────────────────────────
class SummaryScene(Scene):
    def construct(self):
        title = Text("Key Takeaways", font_size=44, color=C_TITLE)
        title.to_edge(UP, buff=0.5)
        self.play(Write(title))

        points = [
            (C_INDEP,
             r"\text{Independent: } \det(A)\neq 0 \;\Rightarrow\; \text{full rank, span grows}"),
            (C_DEP,
             r"\text{Dependent: } \det(A)=0 \;\Rightarrow\; \text{rank deficient, span collapses}"),
            (BLUE,
             r"c_1\vec{v}_1+c_2\vec{v}_2=\vec{0} \;\Rightarrow\; c_1=c_2=0 \;\text{(only for indep.)}"),
            (YELLOW,
             r"\text{Geometric: independent vectors \emph{do not} lie on a common subspace}"),
        ]

        items = VGroup()
        for color, tex in points:
            dot = Dot(color=color, radius=0.08)
            label = MathTex(tex, color=color).scale(0.62)
            row = VGroup(dot, label).arrange(RIGHT, buff=0.25)
            items.add(row)

        items.arrange(DOWN, aligned_edge=LEFT, buff=0.45)
        items.next_to(title, DOWN, buff=0.55)

        for row in items:
            self.play(FadeIn(row, shift=RIGHT * 0.2), run_time=0.6)

        self.wait(3)
        self.play(FadeOut(VGroup(title, items)))


# ─── Master scene: plays everything in order ─────────────────────────────────
class LinearIndependenceScene(Scene):
    """
    Full presentation – run this scene for the complete animation.
    Individual scenes can be rendered separately for faster iteration.
    """

    def construct(self):
        for SceneClass in [
            TitleScene,
            IndependentVectorsScene,
            DependentVectorsScene,
            DeterminantSweepScene,
            SummaryScene,
        ]:
            SceneClass.construct(self)
